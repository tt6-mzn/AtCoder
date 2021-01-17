var __values = (this && this.__values) || function(o) {
    var s = typeof Symbol === "function" && Symbol.iterator, m = s && o[s], i = 0;
    if (m) return m.call(o);
    if (o && typeof o.length === "number") return {
        next: function () {
            if (o && i >= o.length) o = void 0;
            return { value: o && o[i++], done: !o };
        }
    };
    throw new TypeError(s ? "Object is not iterable." : "Symbol.iterator is not defined.");
};
var DISTANCE_LIMIT = 80;
var VARIANCE_LIMIT = 700;
function clamp(x, l, r) {
    return Math.min(Math.max(x, l), r);
}
var Stamp = /** @class */ (function () {
    function Stamp(index, size, r, g, b) {
        this.index = index;
        this.size = size;
        this.r = r;
        this.g = g;
        this.b = b;
    }
    return Stamp;
}());
var StampOp = /** @class */ (function () {
    function StampOp(index, x, y, sign) {
        this.index = index;
        this.x = x;
        this.y = y;
        this.sign = sign;
    }
    return StampOp;
}());
var STAMPS = [
    new Stamp(0, 50, 40, 0, 0),
    new Stamp(1, 50, 0, 40, 0),
    new Stamp(2, 50, 0, 0, 40),
    new Stamp(3, 30, 20, 10, 0),
    new Stamp(4, 30, 0, 20, 10),
    new Stamp(5, 30, 10, 0, 20),
    new Stamp(6, 15, 25, 5, 15),
    new Stamp(7, 15, 15, 25, 5),
    new Stamp(8, 15, 5, 15, 25),
    new Stamp(9, 11, 12, 8, 4),
    new Stamp(10, 11, 4, 12, 8),
    new Stamp(11, 11, 8, 4, 12),
    new Stamp(12, 9, 11, 3, 6),
    new Stamp(13, 9, 7, 12, 1),
    new Stamp(14, 9, 2, 8, 10),
    new Stamp(15, 7, 17, 13, 2),
    new Stamp(16, 7, 2, 16, 14),
    new Stamp(17, 7, 12, 2, 18),
];
var StampSet = /** @class */ (function () {
    function StampSet(canvas, label, stamps) {
        var _this = this;
        this.canvas = canvas;
        this.label = label;
        this.stamps = stamps;
        this.current = 0;
        canvas.width = (StampSet.STAMP_SIZE + 10) * StampSet.COLS + 10;
        canvas.height =
            Math.ceil(STAMPS.length / StampSet.COLS) * (StampSet.STAMP_SIZE + 10) +
                10;
        canvas.onclick = function (e) { return _this.onCanvasClick(e); };
        this.draw();
    }
    StampSet.prototype.currentStamp = function () {
        return this.stamps[this.current];
    };
    StampSet.prototype.getStampByIndex = function (index) {
        return this.stamps[index];
    };
    StampSet.prototype.size = function () {
        return this.stamps.length;
    };
    StampSet.prototype.draw = function () {
        var rows = Math.ceil(STAMPS.length / StampSet.COLS);
        var ctx = this.canvas.getContext("2d");
        ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
        var cur = this.currentStamp();
        this.label.innerHTML = "ID=" + cur.index + "<br/>color=(" + cur.r + ", " + cur.g + ", " + cur.b + ")";
        for (var row = 0; row < rows; ++row) {
            for (var col = 0; col < StampSet.COLS; ++col) {
                var index = row * StampSet.COLS + col;
                var stamp = this.stamps[index];
                var x = (StampSet.STAMP_SIZE + 10) * col + 10;
                var y = (StampSet.STAMP_SIZE + 10) * row + 10;
                ctx.fillStyle = "rgb(" + stamp.r + "," + stamp.g + "," + stamp.b + ")";
                ctx.fillRect(x, y, StampSet.STAMP_SIZE, StampSet.STAMP_SIZE);
                ctx.textAlign = "center";
                ctx.font = "30px serif";
                ctx.fillStyle = "rgb(255, 255, 255)";
                ctx.fillText("" + stamp.size, x + StampSet.STAMP_SIZE / 2, y + StampSet.STAMP_SIZE - 10);
                if (index == this.current) {
                    ctx.strokeStyle = "red";
                    ctx.strokeRect(x - 3, y - 3, StampSet.STAMP_SIZE + 6, StampSet.STAMP_SIZE + 6);
                }
            }
        }
    };
    StampSet.prototype.onCanvasClick = function (ev) {
        var x = ev.offsetX;
        var y = ev.offsetY;
        if (x % (StampSet.STAMP_SIZE + 10) >= 10 &&
            y % (StampSet.STAMP_SIZE + 10) >= 10) {
            var col = Math.floor(x / (StampSet.STAMP_SIZE + 10));
            var row = Math.floor(y / (StampSet.STAMP_SIZE + 10));
            var index = row * StampSet.COLS + col;
            this.current = index;
            this.draw();
        }
    };
    StampSet.STAMP_SIZE = 40;
    StampSet.COLS = 3;
    return StampSet;
}());
var stampSet = new StampSet(document.getElementById("stamps"), document.getElementById("current_stamp"), STAMPS);
var Picture = /** @class */ (function () {
    function Picture(stampSet, canvas, cursorCanvas, graphCanvas, overlayCanvas, numOpsLabel, regionsTable, adjacencyInfoLabel) {
        var _this = this;
        this.stampSet = stampSet;
        this.canvas = canvas;
        this.cursorCanvas = cursorCanvas;
        this.graphCanvas = graphCanvas;
        this.numOpsLabel = numOpsLabel;
        this.regionsTable = regionsTable;
        this.adjacencyInfoLabel = adjacencyInfoLabel;
        this.rs = [];
        this.gs = [];
        this.bs = [];
        this.map = [];
        this.regions = 1;
        this.regX = [];
        this.regY = [];
        this.regCX = [];
        this.regCY = [];
        this.regSize = [];
        this.regR = [];
        this.regG = [];
        this.regB = [];
        this.regRsq = [];
        this.regGsq = [];
        this.regBsq = [];
        this.edges = new Set();
        this.mouseX = null;
        this.mouseY = null;
        this.ops = [];
        this.cursorColorAdd = "rgba(0,0,255,0.5)";
        this.cursorColorSub = "rgba(255,0,0,0.5)";
        for (var y = 0; y < Picture.HEIGHT; ++y) {
            this.map[y] = [];
            for (var x = 0; x < Picture.WIDTH; ++x) {
                this.map[y][x] = 0;
            }
        }
        overlayCanvas.onmousemove = function (e) { return _this.mouseMove(e); };
        overlayCanvas.onmouseleave = function (e) { return _this.clearCursor(e); };
        overlayCanvas.onclick = function (e) { return _this.click(e); };
        overlayCanvas.oncontextmenu = function (e) { return _this.rightClick(e); };
        document.addEventListener("keydown", function (e) { return _this.checkKeyDown(e); });
        document.addEventListener("keyup", function (e) { return _this.checkKeyUp(e); });
        this.init();
        this.initOps();
        this.draw();
    }
    Picture.prototype.init = function () {
        for (var y = 0; y < Picture.HEIGHT; ++y) {
            this.rs[y] = [];
            this.gs[y] = [];
            this.bs[y] = [];
            for (var x = 0; x < Picture.WIDTH; ++x) {
                this.rs[y][x] = 0;
                this.gs[y][x] = 0;
                this.bs[y][x] = 0;
            }
        }
        this.calcRegions();
    };
    Picture.prototype.initOps = function () {
        this.ops = [];
        this.numOpsLabel.innerText = "0";
    };
    Picture.prototype.stamp = function (stamp, sx, sy, subtract, redraw) {
        var size = stamp.size;
        var sign = subtract ? -1 : +1;
        var updated = false;
        for (var dy = 0; dy < size; ++dy) {
            for (var dx = 0; dx < size; ++dx) {
                var yy = sy + dy;
                var xx = sx + dx;
                if (0 <= yy && yy < Picture.HEIGHT && 0 <= xx && xx < Picture.WIDTH) {
                    this.rs[yy][xx] = clamp(this.rs[yy][xx] + sign * stamp.r, 0, 255);
                    this.gs[yy][xx] = clamp(this.gs[yy][xx] + sign * stamp.g, 0, 255);
                    this.bs[yy][xx] = clamp(this.bs[yy][xx] + sign * stamp.b, 0, 255);
                    updated = true;
                }
            }
        }
        if (updated) {
            this.ops.push(new StampOp(stamp.index, sx, sy, sign));
            this.numOpsLabel.innerText = "" + this.ops.length;
            if (redraw) {
                this.forceRedraw();
            }
        }
        return updated;
    };
    Picture.prototype.setupTable = function () {
        var body = this.regionsTable.tBodies[0];
        while (body.rows.length > 0) {
            body.deleteRow(0);
        }
        for (var ri = 0; ri < this.regions; ++ri) {
            var row = document.createElement("tr");
            for (var j = 0; j < 5; ++j) {
                row.appendChild(document.createElement("td"));
            }
            var regionId = row.firstChild;
            regionId.innerText = "" + ri;
            body.appendChild(row);
        }
    };
    Picture.prototype.updateTable = function () {
        var e_1, _a;
        var body = this.regionsTable.tBodies[0];
        for (var ri = 0; ri < this.regions; ++ri) {
            var row = body.childNodes[ri];
            var regionId = row.childNodes[0];
            if (this.checkRegionVariance(ri, VARIANCE_LIMIT)) {
                regionId.style.backgroundColor = "palegreen";
            }
            else {
                regionId.style.backgroundColor = "lightpink";
            }
            var avgColor = row.childNodes[1];
            var color = this.regionColor(ri);
            avgColor.style.backgroundColor = "rgb(" + color[0] + "," + color[1] + "," + color[2] + ")";
            var vars = this.regionVariances(ri);
            for (var i = 0; i < 3; ++i) {
                var variance = row.childNodes[2 + i];
                variance.innerText = "" + vars[i].toFixed(2);
                if (vars[i] <= VARIANCE_LIMIT) {
                    variance.style.backgroundColor = "palegreen";
                }
                else {
                    variance.style.backgroundColor = "lightpink";
                }
            }
        }
        var adj_ok = 0;
        var adj_total = this.edges.size;
        try {
            for (var _b = __values(this.edges), _c = _b.next(); !_c.done; _c = _b.next()) {
                var edge = _c.value;
                var a = edge[0];
                var b = edge[1];
                if (this.regionColorDist(a, b) >= DISTANCE_LIMIT) {
                    ++adj_ok;
                }
            }
        }
        catch (e_1_1) { e_1 = { error: e_1_1 }; }
        finally {
            try {
                if (_c && !_c.done && (_a = _b["return"])) _a.call(_b);
            }
            finally { if (e_1) throw e_1.error; }
        }
        this.adjacencyInfoLabel.innerText = adj_ok + " / " + adj_total;
        if (adj_ok == adj_total) {
            this.adjacencyInfoLabel.style.backgroundColor = "palegreen";
        }
        else {
            this.adjacencyInfoLabel.style.backgroundColor = "lightpink";
        }
    };
    Picture.prototype.undo = function () {
        if (this.ops.length == 0) {
            return;
        }
        var prevOps = this.ops;
        this.init();
        this.initOps();
        for (var i = 0; i < prevOps.length - 1; ++i) {
            var op = prevOps[i];
            this.stamp(this.stampSet.getStampByIndex(op.index), op.x, op.y, op.sign == -1, false);
        }
        this.forceRedraw();
    };
    Picture.prototype.forceRedraw = function () {
        this.calcRegions();
        if (graphView.checked) {
            this.drawGraph();
        }
        this.draw();
        this.updateTable();
    };
    Picture.prototype.loadMapImage = function (img) {
        this.regions = 0;
        this.regX = [];
        this.regY = [];
        this.regSize = [];
        this.edges.clear();
        for (var y = 0; y < Picture.HEIGHT; ++y) {
            for (var x = 0; x < Picture.WIDTH; ++x) {
                this.map[y][x] = -1;
            }
        }
        var edgeNumSet = new Set();
        for (var sy = 0; sy < Picture.HEIGHT; ++sy) {
            for (var sx = 0; sx < Picture.WIDTH; ++sx) {
                if (this.map[sy][sx] != -1) {
                    continue;
                }
                var dx = [0, 1, 0, -1];
                var dy = [1, 0, -1, 0];
                var qx = [];
                var qy = [];
                var cx = 0;
                var cy = 0;
                var qh = 0;
                qx.push(sx);
                qy.push(sy);
                this.map[sy][sx] = this.regions;
                while (qh < qx.length) {
                    var x = qx[qh];
                    var y = qy[qh];
                    var idx = y * Picture.WIDTH * 4 + x * 4;
                    ++qh;
                    cx += x;
                    cy += y;
                    for (var d = 0; d < 4; ++d) {
                        var xx = x + dx[d];
                        var yy = y + dy[d];
                        var iidx = yy * Picture.WIDTH * 4 + xx * 4;
                        if (xx < 0 ||
                            yy < 0 ||
                            xx >= Picture.WIDTH ||
                            yy >= Picture.HEIGHT) {
                            continue;
                        }
                        if (this.map[yy][xx] != -1) {
                            if (this.map[yy][xx] != this.regions) {
                                var edgeNum = this.map[yy][xx] * 1000 + this.regions;
                                if (!edgeNumSet.has(edgeNum)) {
                                    edgeNumSet.add(edgeNum);
                                    this.edges.add([this.map[yy][xx], this.regions]);
                                }
                            }
                            continue;
                        }
                        if (img.data[idx + 0] != img.data[iidx + 0] ||
                            img.data[idx + 1] != img.data[iidx + 1] ||
                            img.data[idx + 2] != img.data[iidx + 2]) {
                            continue;
                        }
                        qx.push(xx);
                        qy.push(yy);
                        this.map[yy][xx] = this.regions;
                    }
                }
                this.regSize.push(qx.length);
                this.regX.push(cx / qx.length);
                this.regY.push(cy / qy.length);
                ++this.regions;
            }
        }
        this.setupTable();
        this.calcRegions();
        this.updateTable();
        return this.regions;
    };
    Picture.prototype.calcRegions = function () {
        this.regR.length = this.regG.length = this.regB.length = this.regions;
        this.regRsq.length = this.regGsq.length = this.regBsq.length = this.regions;
        this.regCX.length = this.regCY.length = this.regions;
        for (var i = 0; i < this.regions; ++i) {
            this.regR[i] = this.regG[i] = this.regB[i] = 0;
            this.regRsq[i] = this.regGsq[i] = this.regBsq[i] = 0;
            this.regCX[i] = this.regCY[i] = -1;
        }
        for (var y = 0; y < Picture.HEIGHT; ++y) {
            for (var x = 0; x < Picture.WIDTH; ++x) {
                var i = this.map[y][x];
                this.regR[i] += this.rs[y][x];
                this.regG[i] += this.gs[y][x];
                this.regB[i] += this.bs[y][x];
                this.regRsq[i] += this.rs[y][x] * this.rs[y][x];
                this.regGsq[i] += this.gs[y][x] * this.gs[y][x];
                this.regBsq[i] += this.bs[y][x] * this.bs[y][x];
                var dx = x - this.regX[i];
                var dy = y - this.regY[i];
                var odx = this.regCX[i] - this.regX[i];
                var ody = this.regCY[i] - this.regY[i];
                if (dx * dx + dy * dy < odx * odx + ody * ody || this.regCX[i] < 0) {
                    this.regCX[i] = x;
                    this.regCY[i] = y;
                }
            }
        }
        this.regCX[5] += 10;
        this.regCY[5] += 10;
        this.regCY[7] -= 40;
        this.regCY[11] += 40;
        this.regCX[13] -= 20;
        this.regCY[13] -= 10;
        this.regCX[15] += 10;
        this.regCY[15] -= 30;
        this.regCX[17] += 45;
        this.regCY[17] -= 30;
        this.regCX[18] += 60;
        this.regCY[18] -= 50;
        this.regCY[25] -= 50;
    };
    Picture.prototype.dumpOperations = function () {
        var res = this.ops.length + "\n";
        for (var i = 0; i < this.ops.length; ++i) {
            var op = this.ops[i];
            res += op.index + " " + op.x + " " + op.y + " " + op.sign + "\n";
        }
        return res;
    };
    Picture.prototype.clearGraph = function () {
        var ctx = this.graphCanvas.getContext("2d");
        ctx.clearRect(0, 0, this.graphCanvas.width, this.graphCanvas.height);
    };
    Picture.prototype.drawGraph = function () {
        var e_2, _a;
        var ctx = this.graphCanvas.getContext("2d");
        ctx.clearRect(0, 0, this.graphCanvas.width, this.graphCanvas.height);
        var oldLineWidth = ctx.lineWidth;
        var NODE_SIZE = 26;
        for (var ri = 0; ri < this.regions; ++ri) {
            var s = this.regSize[ri];
            var r = this.regR[ri] / s;
            var g = this.regG[ri] / s;
            var b = this.regB[ri] / s;
            ctx.fillStyle = "rgb(" + r + "," + g + "," + b + ")";
            ctx.fillRect(50 + this.regCX[ri] - NODE_SIZE / 2, 50 + this.regCY[ri] - NODE_SIZE / 2, NODE_SIZE, NODE_SIZE);
            ctx.lineWidth = 2;
            if (this.checkRegionVariance(ri, VARIANCE_LIMIT)) {
                ctx.strokeStyle = "rgb(0,255,0)";
            }
            else {
                ctx.strokeStyle = "rgb(255,0,0)";
            }
            ctx.strokeRect(50 + this.regCX[ri] - NODE_SIZE / 2, 50 + this.regCY[ri] - NODE_SIZE / 2, NODE_SIZE, NODE_SIZE);
        }
        try {
            for (var _b = __values(this.edges), _c = _b.next(); !_c.done; _c = _b.next()) {
                var edge = _c.value;
                var a = edge[0];
                var b = edge[1];
                ctx.beginPath();
                ctx.moveTo(50 + this.regCX[a], 50 + this.regCY[a]);
                ctx.lineTo(50 + this.regCX[b], 50 + this.regCY[b]);
                ctx.lineWidth = 3;
                ctx.strokeStyle = "rgb(0,0,0)";
                ctx.stroke();
                ctx.beginPath();
                ctx.moveTo(50 + this.regCX[a], 50 + this.regCY[a]);
                ctx.lineTo(50 + this.regCX[b], 50 + this.regCY[b]);
                ctx.lineWidth = 2;
                if (this.regionColorDist(a, b) >= DISTANCE_LIMIT) {
                    ctx.strokeStyle = "rgb(0,255,0)";
                }
                else {
                    ctx.strokeStyle = "rgb(255,0,0)";
                }
                ctx.stroke();
            }
        }
        catch (e_2_1) { e_2 = { error: e_2_1 }; }
        finally {
            try {
                if (_c && !_c.done && (_a = _b["return"])) _a.call(_b);
            }
            finally { if (e_2) throw e_2.error; }
        }
        for (var ri = 0; ri < this.regions; ++ri) {
            var s = this.regSize[ri];
            var r = this.regR[ri] / s >= 128 ? 0 : 255;
            var g = this.regG[ri] / s >= 128 ? 0 : 255;
            var b = this.regB[ri] / s >= 128 ? 0 : 255;
            ctx.textAlign = "center";
            ctx.font = "16px serif";
            ctx.fillStyle = "rgb(" + r + "," + g + "," + b + ")";
            ctx.fillText("" + ri, 50 + this.regCX[ri], 58 + this.regCY[ri]);
        }
        ctx.lineWidth = oldLineWidth;
    };
    Picture.prototype.regionColorDist = function (a, b) {
        var dr = this.regR[a] / this.regSize[a] - this.regR[b] / this.regSize[b];
        var dg = this.regG[a] / this.regSize[a] - this.regG[b] / this.regSize[b];
        var db = this.regB[a] / this.regSize[a] - this.regB[b] / this.regSize[b];
        return Math.sqrt(dr * dr + dg * dg + db * db);
    };
    Picture.prototype.regionColor = function (a) {
        var s = this.regSize[a];
        var r = this.regR[a] / s;
        var g = this.regG[a] / s;
        var b = this.regB[a] / s;
        return [r, g, b];
    };
    Picture.prototype.regionVariances = function (a) {
        var s = this.regSize[a];
        var r = this.regR[a] / s;
        var g = this.regG[a] / s;
        var b = this.regB[a] / s;
        var vr = this.regRsq[a] / s - r * r;
        var vg = this.regGsq[a] / s - g * g;
        var vb = this.regBsq[a] / s - b * b;
        return [vr, vg, vb];
    };
    Picture.prototype.checkRegionVariance = function (a, limit) {
        var vs = this.regionVariances(a);
        return Math.max(vs[0], vs[1], vs[2]) <= limit;
    };
    Picture.prototype.click = function (ev, right) {
        if (right === void 0) { right = false; }
        var stamp = this.stampSet.currentStamp();
        var x = ev.offsetX;
        var y = ev.offsetY;
        var size = stamp.size;
        var subtract = right || ev.altKey || ev.ctrlKey || ev.metaKey;
        var sx = Math.floor(x - 50 - size / 2);
        var sy = Math.floor(y - 50 - size / 2);
        this.stamp(stamp, sx, sy, subtract, true);
    };
    Picture.prototype.rightClick = function (ev) {
        this.click(ev, true);
        ev.preventDefault();
    };
    Picture.prototype.draw = function () {
        var ctx = this.canvas.getContext("2d");
        ctx.strokeStyle = "rgb(0, 0, 0)";
        ctx.strokeRect(49, 49, Picture.WIDTH + 2, Picture.HEIGHT + 2);
        var pixels = ctx.getImageData(50, 50, Picture.WIDTH, Picture.HEIGHT);
        var data = pixels.data;
        var idx = 0;
        for (var y = 0; y < Picture.HEIGHT; ++y) {
            for (var x = 0; x < Picture.WIDTH; ++x) {
                data[idx + 0] = this.rs[y][x];
                data[idx + 1] = this.gs[y][x];
                data[idx + 2] = this.bs[y][x];
                data[idx + 3] = 255;
                idx += 4;
            }
        }
        ctx.putImageData(pixels, 50, 50);
    };
    Picture.prototype.checkKeyDown = function (ev) {
        this.drawCursor(ev.altKey || ev.ctrlKey || ev.metaKey);
        if (ev.key === "z") {
            this.undo();
        }
    };
    Picture.prototype.checkKeyUp = function (ev) {
        this.drawCursor(ev.altKey || ev.ctrlKey || ev.metaKey);
    };
    Picture.prototype.drawCursor = function (subtract) {
        if (this.mouseX == null || this.mouseY == null) {
            return;
        }
        var stamp = this.stampSet.currentStamp();
        var x = this.mouseX;
        var y = this.mouseY;
        var size = stamp.size;
        var ctx = this.cursorCanvas.getContext("2d");
        ctx.clearRect(0, 0, this.cursorCanvas.width, this.cursorCanvas.height);
        if (subtract) {
            ctx.fillStyle = this.cursorColorSub;
        }
        else {
            ctx.fillStyle = this.cursorColorAdd;
        }
        ctx.fillRect(x - size / 2, y - size / 2, size, size);
    };
    Picture.prototype.mouseMove = function (ev) {
        this.mouseX = ev.offsetX;
        this.mouseY = ev.offsetY;
        this.drawCursor(ev.altKey || ev.ctrlKey || ev.metaKey);
    };
    Picture.prototype.clearCursor = function (_) {
        var ctx = this.cursorCanvas.getContext("2d");
        ctx.clearRect(0, 0, this.cursorCanvas.width, this.cursorCanvas.height);
        this.mouseX = null;
        this.mouseY = null;
    };
    Picture.HEIGHT = 400;
    Picture.WIDTH = 800;
    return Picture;
}());
var mapOverlayCanvas = (document.getElementById("map_overlay"));
var pictureBaseCanvas = (document.getElementById("picture_base"));
var picture = new Picture(stampSet, pictureBaseCanvas, document.getElementById("cursor"), document.getElementById("graph"), mapOverlayCanvas, document.getElementById("num_ops"), document.getElementById("regions_table"), document.getElementById("adjacency"));
var loadButton = document.getElementById("load");
loadButton.onclick = function (_) {
    var input = document.getElementById("load_content");
    var stamps = input.value.trim().split("\n");
    var loaded = 0;
    picture.init();
    picture.initOps();
    for (var i = 0; i < stamps.length; ++i) {
        var op = stamps[i].split(" ");
        var id = parseInt(op[0]);
        var x = parseInt(op[1]);
        var y = parseInt(op[2]);
        var sign = parseInt(op[3]);
        if (0 <= id && id < stampSet.size() && (sign == +1 || sign == -1)) {
            if (picture.stamp(stampSet.getStampByIndex(id), x, y, sign == -1, false)) {
                ++loaded;
            }
        }
    }
    picture.forceRedraw();
    var result = document.getElementById("load_result");
    result.innerText = stamps.length + " \u884C\u4E2D " + loaded + " \u884C\u30ED\u30FC\u30C9\u6210\u529F";
};
var dumpButton = document.getElementById("dump");
dumpButton.onclick = function (_) {
    var content = document.getElementById("dump_content");
    content.value = picture.dumpOperations();
};
var mapImage = document.getElementById("map_image");
var mapCanvas = document.createElement("canvas");
function loadMap() {
    mapCanvas.width = mapImage.width;
    mapCanvas.height = mapImage.height;
    var ctx = mapCanvas.getContext("2d");
    ctx.globalAlpha = 1.0;
    ctx.drawImage(mapImage, 0, 0);
    picture.loadMapImage(ctx.getImageData(0, 0, mapImage.width, mapImage.height));
    redrawOverlay();
}
var mapOverlayCtx = mapOverlayCanvas.getContext("2d");
var mapViewRadios = (document.getElementsByName("map_view"));
for (var i = 0; i < mapViewRadios.length; ++i) {
    mapViewRadios[i].onchange = function (_) { return redrawOverlay(); };
}
function redrawOverlay() {
    var selected = "0";
    for (var i = 0; i < mapViewRadios.length; ++i) {
        var radio = mapViewRadios[i];
        if (radio.checked) {
            selected = radio.value;
            break;
        }
    }
    var alpha = parseFloat(selected);
    mapOverlayCtx.clearRect(0, 0, mapOverlayCanvas.width, mapOverlayCanvas.height);
    mapOverlayCtx.globalAlpha = alpha;
    mapOverlayCtx.drawImage(mapImage, 50, 50);
}
var graphView = document.getElementById("graph_view");
graphView.onchange = function (_) {
    if (graphView.checked) {
        picture.drawGraph();
    }
    else {
        picture.clearGraph();
    }
};
var cursorColor = document.getElementById("cursor_color");
var COLORS = [
    ["rgba(0,0,255,0.5)", "rgba(255,0,0,0.5)"],
    ["rgba(0,255,0,0.5)", "rgba(255,0,0,0.5)"],
    ["rgba(255,255,255,0.5)", "rgba(0,0,0,0.5)"],
    ["rgba(0,191,255,0.5)", "rgba(255,69,0,0.5)"],
];
cursorColor.onchange = function (_) {
    var idx = parseInt(cursorColor.value);
    picture.cursorColorAdd = COLORS[idx][0];
    picture.cursorColorSub = COLORS[idx][1];
};
var downloadLink = document.getElementById("download");
downloadLink.onclick = function (_) {
    downloadLink.href = pictureBaseCanvas.toDataURL("image/png");
};

import os

def init():
	file_list = os.listdir("./in_b/")
	for f in file_list:
		with open('./out_b/{}'.format(f), "w") as ff:
			ff.write("init")
		with open('./out_c/{}'.format(f), "w") as ff:
			ff.write("init")

def main():
	file_list = os.listdir("./in_b/")
	for f in file_list:
		os.system("python main.py < ./in_b/{} > ./out_b/{}".format(f, f))
	file_list = os.listdir("./in_c/")
	for f in file_list:
		os.system("python main.py < ./in_c/{} > ./out_c/{}".format(f, f))

if __name__ == "__main__":
	# init()
	main()
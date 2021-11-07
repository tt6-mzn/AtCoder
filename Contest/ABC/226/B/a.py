def main():
    n = int(input())
    La = [tuple(map(int, input().split())) for _ in range(n)]
    print(len(set(La)))

main()
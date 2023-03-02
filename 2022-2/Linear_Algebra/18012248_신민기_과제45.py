import numpy as np

# Matrix 생성 함수
def Create_Matrix(FileName):
    f = open(FileName, "w")

    Equation = int(input()) 
    VecNum = int(input())

    Matrix = [list(map(int, input().split())) for _ in range(Equation)]
    Matrix = np.array(Matrix, dtype=float)
    print(Matrix)

    f.write("Augmented Matrix\n")
    for i in range(Equation):
        for j in range(VecNum+1):
            f.write("{} ".format(Matrix[i][j]))
        f.write("\n")
    f.write("\n\n")
    f.close()

    return Matrix

# RREF form 변환 함수
def rref(FileName, B): 
    A = B.copy()

    # numpy shape: 3 by 4 matrix를 shape할 경우, (3, 4)를 return
    rows, cols = A.shape
    r = 0

    # np.arange: range 함수와 같이 수열을 만들 때 사용
    # ex) np.arange(1, 15, 2): [1, 3, 5, 7, 9, 11, 13] 

    for c in range(cols):
        # np.argmax: 가장 큰 원소의 인덱스를 반환
        # np.abs: 절대값 반환
        # A[r:row, c]: 배열 슬라이싱 / r번째부터 rows번째 행 & c번째 column
        pivot = np.argmax (np.abs (A[r:rows,c])) + r 
        m = np.abs(A[pivot, c])
        # c column에 해당하는 최대값이 0이라면,
        if m == 0:
            # 검사했던 column을 zero column으로 바꿈
            A[r:rows, c] = np.zeros(rows-r)

        # 최대값이 0이 아니라면,
        else:
            # 피봇이 r번째 인덱스가 아니라면,
            if pivot != r:
                # swap
                with open(FileName, "a") as f:
                    f.write("ERO: Row{} <-> Row{}\n".format(pivot+1, r+1))
                A[[pivot, r], c:cols] = A[[r, pivot], c:cols]
                Writing(FileName, A)

            # 피봇을 1로 만들기
            with open(FileName, "a") as f:
                f.write("ERO: ({})Row{} -> Row{}\n".format(1/A[r, c], r+1, r+1))
            A[r, c:cols] = A[r, c:cols] / A[r, c]
            Writing(FileName, A)

            # 피봇 column에서 피봇을 제외한 다른 원소 0으로 만들기
            v = A[r, c:cols]
            # 피봇의 윗 부분
            if r > 0:
                r_above = np.arange(r)
                with open(FileName, "a") as f:
                    f.write("Eliminate upper\n")
                    f.write("ERO: ({})Row{} + Row{} -> Row{}\n".format(- A[r_above, c], c+1, r_above+1, r_above+1))
                A[r_above, c:cols] = A[r_above, c:cols] - np.outer(v, A[r_above, c]).T
                Writing(FileName, A)

            # 피봇의 아래 부분
            if r < rows-1:
                r_below = np.arange(r+1,rows)
                with open(FileName, "a") as f:
                    f.write("Eliminate lower\n")
                    f.write("ERO: ({})Row{} + Row{} -> Row{}\n".format(-A[r_below, c], c+1, r_below+1, r_below+1))
                A[r_below, c:cols] = A[r_below, c:cols] - np.outer(v, A[r_below, c]).T
                Writing(FileName, A)
            r += 1
        
        if r == rows:
            break;
    return A

# Matrix를 파일에 Writing 하는 함수
def Writing(FileName, Mat):
    row, col = Mat.shape

    with open(FileName, "a") as f:
        for i in range(row):
            for j in range(col):
                f.write("{} ".format(Mat[i][j]))
            f.write("\n")
        f.write("\n")

        


while(1):
    # file 이름 입력
    fn = input()

    Aug_Mat = Create_Matrix(fn)
    print("Augmented Matrix\n")
    print(Aug_Mat)

    rref_Mat = rref(fn, Aug_Mat)
    rref_Mat = np.array(rref_Mat, dtype = int)
    print(rref_Mat)

    with open(fn, "a") as f:
        f.write("RREF Matrix\n")
    Writing(fn, rref_Mat)

    #반복 여부 확인
    ch = input()

    if ch != 'Y':
        break
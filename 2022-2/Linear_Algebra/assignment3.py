# 전년도 인구 구하기
import numpy as np
#determinant 계산 함수 
def Det(Matrix):
    det = 0
    length = len(Matrix)

    if length == 2:
        det = Matrix[0][0]*Matrix[1][1] - Matrix[1][0]*Matrix[0][1]
        return det
    else:
        for row in range(length):
            cofactor = Matrix[row][0]
            NewMatrix = np.delete(Matrix,row,axis=0)
            NewMatrix = np.delete(NewMatrix,0,axis=1)

            M = Det(NewMatrix)
            mark = (-1)**(row)
            det += cofactor*mark*M

    return det

#Adjoint Matrix 함수
def Adj(Matrix):
    length = len(Matrix)
    Adj_Matrix = [[0]*len(Matrix) for _ in range(len(Matrix))]
    Adj_Matrix = np.array(Adj_Matrix)
    Adj_Matrix = np.double(Adj_Matrix)

    for i in range(length):
        for j in range(length):
            tmp_Matrix = np.delete(Matrix,i,axis=0)
            tmp_Matrix = np.delete(tmp_Matrix,j,axis=1)
            Adj_Matrix[i][j] = Det(tmp_Matrix)
            if (i+j)%2==1:
                Adj_Matrix[i][j] *= -1
    
    for i in range(length):
        for j in range(i, length):
            if i != j:
                tmp = Adj_Matrix[i][j]
                Adj_Matrix[i][j] = Adj_Matrix[j][i]
                Adj_Matrix[j][i] = tmp

    return Adj_Matrix

#x값 계산 함수; arr1 = A의 역함수, arr2 = 2022년 인구
def sol(arr1, arr2):
    ret = [ [0] * len(arr2[0]) for _ in range(len(arr1)) ]
    ret = np.array(ret)
    ret = np.double(ret)
    for i in range(len(arr1)):
        for j in range(len(arr2[0])):
            for k in range(len(arr1[0])):
                ret[i][j] += arr1[i][k] * arr2[k][j]

    return ret


# a1: 대전 -> 세종 인구 이동 비율
# a2: 대전 -> 천안 인구 이동 비율
a1 = np.double(input())
a2 = np.double(input())
# b1: 세종 -> 대전 인구 이동 비율
# b2: 세종 -> 천안 인구 이동 비율
b1 = np.double(input())
b2 = np.double(input())
# c1: 천안 -> 대전 인구 이동 비율
# c2: 천안 -> 세종 인구 이동 비율
c1 = np.double(input())
c2 = np.double(input())

#2022년 인구
P2022 = [[144], [38], [65]]
P2022 = np.array(P2022)
print("Population of 2022\n{}\n".format(P2022))
# Matrix
M = [[1-a1/100-a2/100, b1/100, c1/100],[a1/100,1-b1/100-b2/100, c2/100], [a2/100,b2/100,1-c1/100-c2/100]]
M = np.array(M)
print("A is equal to\n{}\n".format(M))
# deteminant
detM = Det(M)
print("det={}\n".format(detM))
# # Adjoint matrix
AdjM = Adj(M)
print("Adjoint Maxrix is equal to\n{}\n".format(AdjM))
# inverse Matrix
InverseM = 1/detM * AdjM
print("Inverse Matrix is equla to\n{}\n".format(InverseM))
# Answer
P2021 = sol(InverseM, P2022)
print("2021 Daejeon = {}".format(P2021[0]))
print("2021 Sejong = {}".format(P2021[1]))
print("2021 Cheonan = {}".format(P2021[2]))
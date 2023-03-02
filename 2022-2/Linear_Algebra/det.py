import pandas as pd
import numpy as np 

def det_cofactor(matrix): #first row 기준 전개
    
    det = 0 #결과
    length = len(matrix)
    
    if length == 2: #2차 행렬일 때는 ad-bc 수행
        det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1] 
        return det
    
    else : 
        for row in range(length):
            
            cofactor = matrix[row][0] #cofactor
            #소행렬식
            NewMatrix = np.delete(matrix,row,axis=0) #cofactor가 있는 row 삭제
            NewMatrix = np.delete(NewMatrix,0,axis=1) #cofactor가 있는 col 삭제
            
            
            M = det_cofactor(NewMatrix) #재귀함수 호출
 
            mark = (-1)**(row) #부호 결정
            det += cofactor * mark * M
 
    return det #det값 리턴


#Input 파일 오픈
f = open("Input.txt", 'r')
#첫 줄 = determinant를 계산할 행렬 수
first_line = f.readline().split()
n = int(first_line[0])

#try 횟수
cnt = 0

while True:
    data = f.readline().split()
    #n번 try하면 while문을 탈출
    if cnt == n: break

    if data == []: 
        continue

    else:
        cnt += 1
        row = int(data[0])
        col = int(data[1])
        #square matrix가 아닐 경우
        if row != col:
            with open("Output.txt", 'a') as fw:
                fw.write("determinant %d\n" % cnt)
                fw.write("cannot calculate determinant")
            for i in range(row):
                f.readline()
            continue
        
        matrix = [] #matrix 생성
        for l in range(row): 
            l = f.readline().split()
            matrix.append(l) #데이터 덧붙임

        #DataFrame. '리스트'를 '매트릭스 형태'로 변환
        matrix = pd.DataFrame(matrix) 
        #numpy. '매트릭스 형태'를 '매트릭스'로 변환
        matrix = np.array(matrix.values, dtype=int)
        print(matrix)
    
        det = det_cofactor(matrix)
        print(det)
        with open("Output.txt", 'a') as fw:
            fw.write("determinant %d\n" % cnt)
            fw.write("%d\n" % det)
f.close()
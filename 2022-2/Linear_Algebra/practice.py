import numpy as np 

# RREF form 변환 함수
## 3 by 4 Matrix 가정, [[1,3,3,3], [2,7,8,4], [1,5,1,5]]
def rref(B):  
    A = B.copy()

    # numpy shape: 3 by 4 matrix를 shape할 경우, (3, 4)를 return
    ## A.shape = (3, 4)
    rows, cols = A.shape  

    r = 0

    # 피봇 위치 저장 list
    pivots_pos = []

    # np.arange: range 함수와 같이 수열을 만들 때 사용
    # ex) np.arange(1, 15, 2): [1, 3, 5, 7, 9, 11, 13] 
    ## np.arange(3) = [0,1,2]
    row_exchanges = np.arange(rows)   

    ## c는 0부터 3까지
    for c in range(cols): 
        ## Find the pivot row:
        # np.argmax: 가장 큰 원소의 인덱스를 반환
        # np.abs: 절대값 반환
        # A[r:rows, c]: 배열 슬라이싱 / r+1번째부터 rows번째 행 & c번째 column
        # A[0:3, 0]: [1 2 1] (즉, 첫 번째 column 검사 작업)
        ## c가 0일 경우, r이 0일 경우, 
        ## np.argmax(np.abs(A[0:3, 0])) + 0 = "1" -> 2번째 인덱스
        pivot = np.argmax (np.abs (A[r:rows,c])) + r # column 검사
        ## np.abs(A[1, 0]) = 2
        m = np.abs(A[pivot, c])
        
        # c column에 해당하는 최댓값이 0이라면,
        if m == 0:
            # 검사했던 column을 zero column으로 바꿈
            A[r:rows, c] = np.zeros(rows-r)

        # 최대값이 0이 아니라면,
        else:
            ## keep track of bound variables
            pivots_pos.append((r,c))
            # 피봇이 r번째 인덱스가 아니라면,
            if pivot != r:
                ## Swap current row and pivot row
                A[[pivot, r], c:cols] = A[[r, pivot], c:cols]
                row_exchanges[[pivot,r]] = row_exchanges[[r,pivot]]

            ## Normalize pivot row
            A[r, c:cols] = A[r, c:cols] / A[r, c];

            ## Eliminate the current column
            v = A[r, c:cols]
            ## Above (before row r):
            if r > 0:
                ridx_above = np.arange(r)
                A[ridx_above, c:cols] = A[ridx_above, c:cols] - np.outer(v, A[ridx_above, c]).T
                

            ## Below (after row r):
            if r < rows-1:
                ridx_below = np.arange(r+1,rows)
                A[ridx_below, c:cols] = A[ridx_below, c:cols] - np.outer(v, A[ridx_below, c]).T
                
            r += 1
        ## Check if done
        if r == rows:
            break;

    return A



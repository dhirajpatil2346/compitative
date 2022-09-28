def accept_matrix(M):
    print("Enter the row and column of the matrices : ")
    r = int(input("\t row = "))
    c = int(input("\t column = "))
    print("Enter the elements in the matrix")
    for i in range (r):
        A = []
        for j in range (c):
            A.append(int(input()))
        M.append(A)

def addition_Matrix(M1,M2,M3,r,c) :
    for i in range (r):
        a =[]
        for j in range (c):
            a.append((M1[i][j])+(M2[i][j]))
        M3.append(a)

def substraction_Matrix(M1,M2,M3,r,c) :
    for i in range (r):
        a =[]
        for j in range (c):
            a.append((M1[i][j])-(M2[i][j]))
        M3.append(a)
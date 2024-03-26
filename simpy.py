import numpy as np
import sympy as sp
from sympy.matrices import Matrix, MatrixSymbol, MatMul

from sympy import (MatrixSymbol, BlockMatrix, symbols,
    Identity, ZeroMatrix, symmetrize, block_collapse)

print("import sympy")

def algbra():
    # Define symbolic variables
    x, y = sp.symbols('x y')

    # Create a symbolic expression
    expr = x**2 + 2*x*y + y**2

    # Expand the expression
    expanded_expr = sp.expand(expr)

    # Simplify the expression
    simplified_expr = sp.simplify(expanded_expr)

    # Differentiate the expression with respect to x
    diff_expr = sp.diff(simplified_expr, x)

    # Solve an equation
    eq = sp.Eq(diff_expr, 0)
    sol = sp.solve(eq, x)

    # Print the results
    print("Expression:")
    print(expr)

    print("Expanded expression:")
    print(expanded_expr)

    print("Simplified expression:")
    print(simplified_expr)

    print("Differentiated expression:")
    print(diff_expr)

    print("Solution to the equation:")
    print(sol)

def func():
# Define the symbolic matrix
    A = sp.MatrixSymbol('A', 3, 3)
   
    # Calculate the square of the matrix
    A_squared = A**2

    # Calculate the determinant of the matrix
    det_A = A.det()

    # Calculate the inverse of the matrix
    A_inv = A.inv()

    # Print the results
    print("A^2:")
    print(A_squared)

    print("Determinant of A:")
    print(det_A)

    print("Inverse of A:")
    print(A_inv)
    print("done")

def doMatrixSym():
    # Define symbolic variables
    a, b, c, d, e, f, g, h = sp.symbols('a b c d e f g h')

    # Create symbolic matrices
    G = Matrix([[a, b, 0, c], 
                [b, d, 0, e],
                [0, 0, f, g],
                [c, e, g, h]])
    V = Matrix([[-b/a, 0, -c/a], 
                [1, 0, 0],
                [0, 1, 0],
                [0, 0, 1]])

    # Matrix addition
    #C = A + B

    # Matrix multiplication
    D = V.T * G * V

    # Scalar multiplication
    #E = 2 * A

    # Matrix transpose
    #F = A.T

    # Matrix inverse
    #G = A.inv()

    # Print the results
    print("Matrix V:")
    print(V)

    print("Matrix G:")
    print(G)

    #print("Matrix addition (A + B):")
    #print(C)

    print("Matrix multiplication (V.T * G * V):")
    
    print(sp.simplify(D))

    #print("Scalar multiplication (2 * A):")
    #print(E)

    #print("Matrix transpose of A:")
    #print(F)

    #print("Matrix inverse of A:")
    #print(G)


def doSymbolMatrix():
    n,m,l = symbols('n m l')
    X = MatrixSymbol('X', n, n)
    Y = MatrixSymbol('Y', m, m)
    Z = MatrixSymbol('Z', n, m)
    B = BlockMatrix([[X, Z], [ZeroMatrix(m,n), Y]])
    print(B)

    C = BlockMatrix([[Identity(n), Z]])
    print(C)
    print("C*B")
    print(block_collapse(C*B))

def inverseIdensity():
    n = symbols('n')
    A = MatrixSymbol('A', m = n, n = n) #symmetric = True
    
    print("calculate normal A*(Ainv.T)")
    mat = A*(A.inverse().T)
    print(block_collapse( mat ))


    Asym = A+A.T ## build a symmetric matrix
    print("calculate symmetric A*(Ainv.T)")
    print(block_collapse(Asym*(Asym.inv().T) ))

def setsymmetricMatrix():
    M = MatrixSymbol('M', 3, 3)
    print(M.as_explicit())

    Msym = Matrix(3, 3, lambda i, j: M[min(i,j),max(i,j)])
    print(Msym)

    print(" is symmtric ")
    print(Msym.is_symmetric())

def getSmmetric(M):
    Msym = Matrix(3, 3, lambda i, j: M[min(i,j),max(i,j)])
    print("is symmtric ")
    print(Msym.is_symmetric())
    return Msym

def setEquations():
    from sympy.matrices import MatrixSymbol, Transpose, Inverse
    # Define the matrix symbol
    n = sp.symbols('n', integer=True)
    A = MatrixSymbol('A', n, n)

    # Create the transpose and inverse of A
    A_transpose = Transpose(A)
    A_inverse = Inverse(A)

    # Create the equation stating the rule
    equation = sp.Equality(A_transpose, A_inverse)

    # Print the equation
    print(equation)

def substuteExpresion():
    x, y, z, a,b = sp.symbols('x y z a b')
    expr = x**2 + y*z + z**2

    # Using subs() method
    substituted_expr1 = expr.subs([(x, a), (z, b)])
    print("Substituted expression (using subs() method):", substituted_expr1)



def doSymbolTransforVGV():
    n,m,l = symbols('n m l')
    #G11R = MatrixSymbol('G11R', m, m)
    basic = MatrixSymbol("basic", m, m)
    G11R = (basic + basic.T) #build a symmetric symbol  matrix
    G11S = MatrixSymbol('G11S', n, n)
    G11K = MatrixSymbol('G11K', m, n)
    
    G13R = MatrixSymbol('G13R', m, l)
    G13S = MatrixSymbol('G13S', n, l)

    G22 = MatrixSymbol('G22', m, m)
    G23 = MatrixSymbol('G23', m, l)

    G33 = MatrixSymbol('G33', l, l)
    
    G = BlockMatrix([
                    [G11R, G11K, ZeroMatrix(m, m), G13R], 
                    [G11K.T, G11S, ZeroMatrix(n, m), G13S],
                    [ZeroMatrix(m, m),ZeroMatrix(m, n), G22, G23],
                    [G13R.T, G13S.T, G23.T, G33]
                    ])
    print("\nG matirx\n")
    print(G)

    # TM = BlockMatrix([
    #                 [-G11R.inverse()*G11K, ZeroMatrix(m, m), -G11R.inverse()*G13R],
    #                 [Identity(n), ZeroMatrix(n, m), ZeroMatrix(n, l)],
    #                 [ZeroMatrix(m, n), Identity(m), ZeroMatrix(m, l)],
    #                 [ZeroMatrix(l, n), ZeroMatrix(l, m), Identity(l)] 
    #                 ])
    # print(TM)

    V = BlockMatrix([
                    [-G11R.inverse()*G11K, ZeroMatrix(m, m), -G11R.inverse()*G13R],
                    [Identity(n), ZeroMatrix(n, m), ZeroMatrix(n, l)],
                    [ZeroMatrix(m, n), Identity(m), ZeroMatrix(m, l)],
                    [ZeroMatrix(l, n), ZeroMatrix(l, m), Identity(l)] 
                     ])
    print("\nV matirx\n")
    print(V)

    print("\nV.T*G*V\n")
    print(block_collapse(V.T*G*V))
    print("\nTo get final expresion please:\n "
          " relace symbol \"{}\" with \"{}\" ".format(G11R, "G11R"))


if __name__=="__main__":
   
    #algbra()
    #func()
    #doMatrixSym()
    #doSymbolMatrix()

    #inverseIdensity()

    doSymbolTransforVGV()
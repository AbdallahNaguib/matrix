#ifndef MATRIX_H
#define MATRIX_H


class Matrix{
public:
    int** data;
    int row, col;
    Matrix operator+  (Matrix mat2); // Add if same dimensions
    Matrix operator-  (Matrix mat2); // Sub if same dimensions
    Matrix operator*  (Matrix mat2); // Multi if col1 == row2
    Matrix operator+  (int scalar);  // Add a scalar
    Matrix operator-  (int scalar);  // Subtract a scalar
    Matrix operator*  (int scalar);  // Multiple by scalar

    // ABDULAZIZ FUNCTIONS
    // The last operator >> takes an istream and a Matrix and return the
    // the same istream so it is possible to cascade input like
    // cin >> Matrix1 >> Matrix2 << endl;
    void operator+= (Matrix mat2); // mat1 changes & return
                            // new Matrix with the sum
    void operator-= (Matrix mat2); // mat1 changes + return new
                             // Matrix with difference
    void operator+= (int scalar);   // change mat & return new Matrix
    void operator-= (int scalar);   // change mat & return new Matrix
    void operator++ ();   	// Add 1 to each element ++mat
    void operator-- ();    	// Sub 1 from each element --mat

            // Print Matrix  as follows (2 x 3)			4	 6 	  8
               // and return ostream to cascade printing	9	12  	123
    bool   operator== (Matrix mat2);	// True if identical
    bool   operator!= (Matrix mat2); 	// True if not same
    bool   isSquare   ();  // True if square Matrix
    bool   isSymetric ();  // True if square and symmetric
    bool   isIdentity ();  // True if square and identity
    Matrix transpose ();    // Return new Matrix with the transpose
};

#endif // MATRIX_H

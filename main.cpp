#include <iostream>
#include <Matrix.h>
using namespace std;
istream& operator>> (istream& in, Matrix& mat);
ostream& operator<< (ostream& out, Matrix& mat);
int main(){
    st:
    Matrix mat1, mat2, mat3;
    int scalar, num;
    cout << "Enter the number of the process you want to do on matrices.\n";
    cout << "1- Add tow matrices in a new Matrix.\n"
         << "2- Subtract tow matrices in a new Matrix.\n"
         << "3- Multiply tow matrices in a new Matrix.\n"
         << "4- Add a scalar.\n"
         << "5- Subtract a scalar.\n"
         << "6- Multiply a scalar.\n"
         << "7- Add tow matrices in a Matrix1.\n"
         << "8- Subtract tow matrices in Matrix1.\n"
         << "9- Add a scalar to Matrix1.\n"
         << "10-Subtract a scalar form Matrix1.\n"
         << "11- ++mat.\n"
         << "12- --mat.\n"
         << "13- Check if Matrix1 = Matrix2 or not.\n"
         << "14- Check if Matrix1 is square.\n"
         << "15- Check if Matrix1 is symmetric.\n"
         << "16- Check if Matrix1 is identical.\n"
         << "17- Transpose Matrix1.\n";
    cout << "Please, Choose:";
    cin >> num;
    cout << "Please enter Matrix1.\n";
    cin >> mat1;
    if(num == 1){
        try{
            cout << "Please enter Matrix2.\n";
            cin >> mat2;
            mat3 = mat1 + mat2;
            cout << mat3 << endl;
        }catch(int x){
            cout<<"cannot add"<<endl;
        }
    }
    else if(num == 2){
        try{
            cout << "Please enter Matrix2.\n";
            cin >> mat2;
            mat3 = mat1 - mat2;
            cout << mat3 << endl;
        }catch(int x){
            cout<<"cannot subtract"<<endl;
        }
    }
    else if(num == 3){
        try{
            cout << "Please enter Matrix2.\n";
            cin >> mat2;
            mat3 = mat1 * mat2;
            cout << mat3 << endl;
        }catch(int x){
            cout<<"cannot multiply"<<endl;
        }
    }
    else if(num == 4){
        cout << "Please enter scalar.\n";
        cin >> scalar;
        mat3 = mat1 + scalar;
        cout << mat3 << endl;
    }
    else if(num == 5){
        cout << "Please enter scalar.\n";
        cin >> scalar;
        mat3 = mat1 - scalar;
        cout << mat3 << endl;
    }
    else if(num == 6){
        cout << "Please enter scalar.\n";
        cin >> scalar;
        mat3 = mat1 * scalar;
        cout << mat3 << endl;
    }
    else if(num == 7){
        try{
            cout << "Please enter Matrix2.\n";
            cin >> mat2;
            mat1 += mat2;
            cout << mat1 << endl;
        }catch(int x){
            cout<<"can't add"<<endl;
        }
    }
    else if(num == 8){
        try{
            cout << "Please enter Matrix2.\n";
            cin >> mat2;
            mat1 -= mat2;
            cout << mat1 << endl;
        }catch(int x){
            cout<<"can't subtract"<<endl;
        }
    }
    else if(num == 9){
        cout << "Please enter scalar.\n";
        cin >> scalar;
        mat1 += scalar;
        cout << mat1 << endl;
    }
    else if(num == 10){
        cout << "Please enter scalar.\n";
        cin >> scalar;
        mat1 -= scalar;
        cout << mat1 << endl;
    }
    else if(num == 11){
        ++mat1;
        cout << mat1 << endl;
    }
    else if(num == 12){
        --mat1;
        cout << mat1 << endl;
    }
    else if(num == 13){
        cout << "Please enter Matrix2.\n";
        cin >> mat2;
        if(mat1 == mat2)
            cout << "Matrix1 = Matrix2\n";
        else
            cout << "Matrix1 != Matrix2\n";
    }
    else if(num == 14){
        if(mat1.isSquare())
            cout << "Matrix1 is square.\n";
        else
            cout << "Matrix1 isn't square.\n";
    }
    else if(num == 15){
        if(mat1.isSymetric())
            cout << "Matrix1 is symmetric.\n";
        else
            cout << "Matrix1 isn't symmetric.\n";
    }
    else if(num == 16){
        if(mat1.isIdentity())
            cout << "Matrix1 is identical.\n";
        else
            cout << "Matrix1 isn't identical.\n";
    }
    else if(num == 17){
        mat3 = mat1.transpose();
        cout << mat3;
    }
    cout<<endl<<endl<<endl<<endl<<endl;
    goto st;
    return 0;
}

istream& operator>> (istream& in, Matrix& mat){
    int row,col;
    cout << "Enter rows and cols" << endl;
    in >> row >> col;
    cout << "Enter the Matrix "<<endl;
    mat.row = row;
    mat.col = col;
    mat.data = new int*[row];
    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            in >> mat.data[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, Matrix& mat){
    for(int i=0 ; i<mat.row ; i++){
        for(int j=0 ; j<mat.col ; j++){
            out << mat.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

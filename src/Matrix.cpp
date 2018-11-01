#include "Matrix.h"

Matrix Matrix::operator+(Matrix mat2){
    Matrix resMat;
    if(this->row != mat2.row || this->col != mat2.col){
        throw 0;
    }
    resMat.row=this->row;
    resMat.col=this->col;
    resMat.data=new int*[resMat.row];
    for (int i = 0; i < resMat.row; i++){
        resMat.data[i] = new int [resMat.col];
    }
    for(int i=0 ; i<resMat.row ; i++){
        for(int j=0 ; j<resMat.col ; j++){
            resMat.data[i][j]=this->data[i][j]+mat2.data[i][j];
        }
    }
    return resMat;
}

Matrix Matrix::operator-( Matrix mat2){
    if(this->row != mat2.row || this->col != mat2.col){
        throw 0;
    }
    Matrix resMat;
    resMat.row=this->row;
    resMat.col=this->col;
    resMat.data=new int*[resMat.row];
    for (int i = 0; i < resMat.row; i++){
        resMat.data[i] = new int [resMat.col];
    }
    for(int i=0 ; i<resMat.row ; i++){
        for(int j=0 ; j<resMat.col ; j++){
            resMat.data[i][j]=this->data[i][j]-mat2.data[i][j];
        }
    }
    return resMat;
}

Matrix Matrix::operator*(Matrix mat2){
    if(this->col != mat2.row){
        throw 0;
    }
    Matrix resMat;
    resMat.row=this->row;
    resMat.col=mat2.col;
    resMat.data = new int* [resMat.row];
    for (int i = 0; i < resMat.row; i++){
        resMat.data[i] = new int [resMat.col];
    }
    for(int i=0 ; i<resMat.row ; i++){
        for(int j=0 ; j<resMat.col ; j++){
            int sum=0;
            int x=0;
            /*
                we need to multiply each row by each col and take their sum
                so initialize var x to walk through all the cols with row (i) in mat1
                ato walk through all the rows in col (j) in mat2
                */
            for(; x<this->col ; x++){//we assume that this->col = mat2.row
                sum+=this->data[i][x] * mat2.data[x][j];
            }
            resMat.data[i][j]=sum;
        }
    }
    return resMat;
}

Matrix Matrix::operator+(int scalar){
    Matrix resMat;
    resMat.row=this->row;
    resMat.col=this->col;
    resMat.data = new int* [resMat.row];
    for (int i = 0; i < resMat.row; i++){
        resMat.data[i] = new int [resMat.col];
    }
    for(int i=0 ; i<resMat.row ; i++){
        for(int j=0 ; j<resMat.col ; j++){
            resMat.data[i][j]=this->data[i][j]+scalar;
        }
    }
    return resMat;
}

Matrix Matrix::operator-(int scalar){
    Matrix resMat;
    resMat.row=this->row;
    resMat.col=this->col;
    resMat.data = new int* [resMat.row];
    for (int i = 0; i < resMat.row; i++){
        resMat.data[i] = new int [resMat.col];
    }
    for(int i=0 ; i<resMat.row ; i++){
        for(int j=0 ; j<resMat.col ; j++){
            resMat.data[i][j]=this->data[i][j]-scalar;
        }
    }
    return resMat;
}

Matrix Matrix::operator*(int scalar){
    Matrix resMat;
    resMat.row=this->row;
    resMat.col=this->col;
    resMat.data = new int* [resMat.row];
    for (int i = 0; i < resMat.row; i++){
        resMat.data[i] = new int [resMat.col];
    }
    for(int i=0 ; i<resMat.row ; i++){
        for(int j=0 ; j<resMat.col ; j++){
            resMat.data[i][j]=this->data[i][j]*scalar;
        }
    }
    return resMat;
}

//***********************
//ABDULAZIZ'S TASK:

void Matrix::operator++ (){
    for(int i = 0 ; i < this->row ; ++i){
        for(int j = 0 ; j < this->col ; j++){
            this->data[i][j] = this->data[i][j] + 1;
        }
    }
}

void Matrix::operator-- (){
    int row, col;
    row = this->row;
    col = this->col;
    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; j++){
            this->data[i][j] = this->data[i][j] - 1;
        }
    }
}
void Matrix::operator+= (int scalar){

    int row, col;
    row = this->row;
    col = this->col;
    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; j++){
            this->data[i][j] = this->data[i][j] + scalar;
        }
    }
}

void Matrix::operator-=(int scalar){
    int row, col;
    row = this->row;
    col = this->col;
    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; j++){
            this->data[i][j] = this->data[i][j] - scalar;
        }
    }
}

void Matrix::operator+= ( Matrix mat2){
    if(this->row != mat2.row || this->col != mat2.col){
        throw 0;
    }
    int row, col;
    row = this->row;
    col = this->col;
    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; j++){
            this->data[i][j] = this->data[i][j] + mat2.data[i][j];
        }
    }
}

void Matrix::operator-=(Matrix mat2){
    if(this->row != mat2.row || this->col != mat2.col){
        throw 0;
    }
    int row, col;
    row = this->row;
    col = this->col;
    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; j++){
            this->data[i][j] = this->data[i][j] - mat2.data[i][j];
        }
    }
}


bool Matrix::operator==(Matrix mat2){
    for ( int i=0; i<this->row ;i++){
        for(int j=0 ; j<this->col ; j++){
            if (this->data[i][j]!=mat2.data[i][j] ){
            return false;
            }
        }
    }
return true;
}
bool Matrix::operator!=(Matrix mat2){
   for ( int i=0; i<this->row ;i++){
        for(int j=0 ; j<this->col ; j++){
            if (this->data[i][j]!=mat2.data[i][j])
                return true;
        }
   }
return false;
}
bool Matrix::isSquare(){
    if (this->row==this->col)
        return true;
    else
        return false;

}
bool Matrix::isSymetric(){
    int check=0;
    for(int i=0 ; i<this->row ; i++){
        for(int j=0 ; j<this->col ; j++){
            if(i==j)continue;
            else
                if(this->data[i][j]!=this->data[j][i]) check+=1;
        }
    }
    if(check==0) return true;
    else  return false;
}
bool Matrix::isIdentity(){
     int checkZero=0 , checkone=0;
     for(int i=0 ; i<this->row ; i++){
        for(int j=0 ; j<this->col ; j++){
            if (i==j){
                if (this->data[i][j]!=1) checkone+=1;
            }
            else
               if(this->data[i][j]!=0) checkZero+=1;
        }
     }
     if(checkone==0 && checkZero==0) return true;
     else return false;
}
Matrix Matrix::transpose(){
     Matrix resMat;
     resMat.row=this->col;
     resMat.col=this->row;
     resMat.data = new int* [resMat.row];
     for (int i = 0; i < resMat.row; i++){
        resMat.data[i] = new int [resMat.col];
     }
     for(int i=0 ; i<resMat.row ; i++){
        for(int j=0 ; j<resMat.col ; j++){
            resMat.data[i][j]=this->data[j][i];
        }
     }
    return resMat;
}


    #include<iostream>
    #include<vector>
    using namespace std;

    class Matrix
    {
        private:
        int row,column;
        public:
        vector<vector<int>> mat;
        Matrix();
        Matrix(int,int);
        Matrix(const Matrix&);
        ~Matrix();
        void display();
    };

    Matrix::Matrix()
    {
        row=0,column=0;
        mat.resize(row,vector<int>(column));
        cout<<"Matrix constructed but no space is utilized\n";
    }

    Matrix::Matrix(int a,int b)
    {
        row=a,column=b;
        mat.resize(row,vector<int>(column));
        cout<<"Matric constructed.\nEneter the Elements:\n";
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                cin>>mat[i][j];
            }
        }
    }

    Matrix::Matrix(const Matrix& m)
    {
        row = m.row;
        column = m.column;
        mat = m.mat;  
        
    }

    Matrix::~Matrix()
    {
        cout<<"Matrix destroyed\n";
    }

    void Matrix::display()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    int  main()
    {
        Matrix a,b(1,3);
        Matrix c(b);
        a.display();
        b.display();
        c.display();

    }
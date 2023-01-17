#include <iostream>
using namespace std;

int main()
{
    int n, nx, i, j, out, db, fx;
    float th;
    int ak, akurasi = 0;

    cout << "Masukkan Banyak Data\t: ";
    cin >> n;
    cout << "Input Banyak x\t\t: ";
    cin >> nx;
    cout << "Masukkan Treshold\t: ";
    cin >> th;

    int dw[nx], w[nx], x[n][nx], t[nx];

    for (i = 0; i < nx; i++)
    {
        w[i] = 0;
        dw[i] = 0;
    }

    cout << endl;

    // Tahap Input
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < nx; j++)
        {
            cout << "Input X" << j + 1 << " Data Ke-" << i + 1 << "\t= ";
            cin >> x[i][j];
        }

        cout << "Input T Data Ke-" << i + 1 << "\t= ";
        cin >> t[i];
        cout << endl;
    }

    // Tahap Learning
    int a = 1, epoch = 1, b = 0;
    while (akurasi != 1)
    {
        cout << "\nEPOCH Ke-" << epoch << endl;
        for (i = 0; i < nx; i++)
        {
            cout << "X" << i + 1 << "\t";
        }

        cout << "T\t";
        cout << "F(x)\t";
        cout << "Y\t";
        cout << "AKURASI\t";

        for (i = 0; i < nx; i++)
        {
            cout << "W" << i + 1 << "\t";
        }

        cout << "B";
        cout << endl;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < nx; j++)
            {
                cout << x[i][j] << "\t";
            }

            cout << t[i] << "\t";

            fx = 0;
            for (j = 0; j < nx; j++)
            {
                fx = fx + (w[j] * x[i][j]);
            }

            fx = fx + b;
            cout << fx << "\t";

            out = 0;
            if (fx > th)
            {
                out = 1;
            }
            else if (fx < th * -1)
            {
                out = -1;
            }
            else
            {
                out = 0;
            }

            if (out == t[i])
            {
                ak = 1;
            }
            else
            {
                ak = 0;
            }

            cout << out << "\t";
            cout << ak << "\t";

            if (ak == 0)
            {
                for (j = 0; j < nx; j++)
                {
                    dw[j] = a * x[i][j] * t[i];
                }

                db = a * t[i];
                for (j = 0; j < nx; j++)
                {
                    w[j] = w[j] + dw[j];
                }

                b = b + db;
            }
            else
            {
                akurasi++;
            }

            for (j = 0; j < nx; j++)
            {
                cout << w[j] << "\t";
            }

            cout << b << "\t";
            cout << endl;
        }
        akurasi = akurasi / n;
        epoch++;
    }

    int re = 0;
    while (re != n)
    {
        cout << "Algoritma Testing\n";
        cout << "data ke -" << re + 1 << endl;
        for (i = 0; i < nx; i++)
        {
            cout << "W" << i + 1 << " = " << w[i] << endl;
        }
        cout << "B = " << b << endl;

        int tx[nx];
        for (i = 0; i < nx; i++)
        {
            cout << "Input X" << i + 1 << " = ";
            cin >> tx[i];
        }

        fx = 0;

        for (i = 0; i < nx; i++)
        {
            fx += w[i] * tx[i];
        }
        fx = fx + b;
        cout << endl;
        cout << "Hasil Algoritma Learning" << endl;
        cout << "F(X) = " << fx << endl;

        out = 0;
        if (fx > th)
        {
            out = 1;
        }
        else if (fx < th * -1)
        {
            out = -1;
        }
        else
        {
            out = 0;
        }
        cout << "output = " << out << endl;
        cout << endl;
        re++;
    }
}
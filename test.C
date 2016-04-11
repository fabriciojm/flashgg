void test (string j = "hola") {
    result = j + " (fake) ";
    const char *vari = result.c_str();
    cout << vari << "Value of j fake \n";
    result = j + " (prompt) ";
    vari = result.c_str();
    cout << vari << "Value of j prompt \n";
    int a = 3;
    cout << a << " <-- A value\n";
    a = 4;
    cout << 4 << " <-- A changed\n";
    }

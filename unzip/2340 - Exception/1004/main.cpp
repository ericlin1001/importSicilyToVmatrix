void test(int a, int b) {
    try {
        cout << calc(a, b) << endl;
    }
    catch (out_of_range e){
        cout << e.what() << endl;
    }
    catch (logic_error e) {
        cout << e.what() << endl;
    }
}                                 


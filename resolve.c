/*

Build a JSON serializer that will pass the test cases shown below.

* Memory leaks will decrease your final punctuation
* You are not allowed to use third party libraries, just our code and STL.
* You are not allowed to modify the tests or the main program.

*/



size_t execute_test_1()
{
        json_number n{ 24 };

        auto r = n.serialize();

        return r == "24";
}

size_t execute_test_2()
{
        json_string s = "hello world";

        auto r = s.serialize();

        return r == "\"hello world\"";
}

size_t execute_test_3()
{
        json_bool b = false;
        auto r = b.serialize();
        return r == "false";
}

size_t execute_test_4()
{
        json_array a;
        auto r = a.serialize();

        return r == "[]";
}
size_t execute_test_5()
{
        json_array a;
        auto r = a.add(new json_number(104)).add(new json_number(5)).add(new json_number(31415)).serialize();

        return r == "[104, 5, 31415]";
}

size_t execute_test_6()
{
        json_array a;
        auto r = a.add(new json_string("juan lopez")).add(new json_number(1938232)).add(new json_bool(true)).serialize();
        return r == "[\"juan lopez\", 1938232, true]";
}

size_t execute_test_7()
{
        json_object obj;
        auto r = obj.serialize();

        return r == "{ }";
}

size_t execute_test_8()
{
        json_object obj;
        obj.add("nombre", new json_string("romulo"));
        obj.add("apellido", new json_string("rojas"));
        obj.add("rol", new json_string("dev killer"));

        auto r = obj.serialize();

        return r == "{ \"nombre\" : \"romulo\", \"apellido\" : \"rojas\", \"rol\" : \"dev killer\" }";
}

size_t execute_test_9()
{
        auto obj1 = new json_object();
        obj1->add("mes", new json_string("marzo"));
        obj1->add("dia", new json_number(16));

        auto obj2 = new json_object();
        obj2->add("mes", new json_string("abril"));
        obj2->add("dia", new json_number(1));

        json_array a;
        auto r = a.add(obj1).add(obj2).serialize();

        return r == "[{ \"mes\" : \"marzo\", \"dia\" : 16 }, { \"mes\" : \"abril\", \"dia\" : 1 }]";
}

size_t execute_test_10()
{
        json_object complex;

        complex.add("nombre", new json_string("juan perez"));

        auto arr = new json_array();
        arr->add(new json_string("jperez@gmail.com")).add(new json_string("choquito432@hotmail.com"));

        complex.add("emails", arr);

        auto direcciones = new json_array();

        auto dir1 = new json_object();
        dir1->add("descripcion", new json_string("casa"));
        dir1->add("direccion", new json_string("juan de la rosa 2345"));

        auto dir2 = new json_object();
        dir2->add("descripcion", new json_string("trabajo"));
        dir2->add("direccion", new json_string("melchor perez 2643"));

        direcciones->add(dir1);
        direcciones->add(dir2);

        complex.add("direcciones", direcciones);

        auto r = complex.serialize();

        return r == "{ \"nombre\" : \"juan perez\", \"emails\" : [\"jperez@gmail.com\", \"choquito432@hotmail.com\"], \"direcciones\" : [{ \"descripcion\" : \"casa\", \"direccion\" : \"juan de la rosa 2345\" }, { \"descripcion\" : \"trabajo\", \"direccion\" : \"melchor perez 2643\" }] }";
}

size_t execute_test_11()
{
        json_array a;

        a.add(new json_string("jorge \"chapo\" guzman"));
        a.add(new json_null());
        a.add(new json_string("mc donald's"));

        auto r = a.serialize();

        return r == "[\"jorge \\\"chapo\\\" guzman\", null, \"mc donald's\"]";
}


int main()
{
        size_t success_count = 0;

        success_count += execute_test_1();
        success_count += execute_test_2();
        success_count += execute_test_3();
        success_count += execute_test_4();
        success_count += execute_test_5();
        success_count += execute_test_6();
        success_count += execute_test_7();
        success_count += execute_test_8();
        success_count += execute_test_9();
        success_count += execute_test_10();
        success_count += execute_test_11();

        cout << "SUCCESS COUNT: [" << success_count << " / 11]\n";
        return 0;
}
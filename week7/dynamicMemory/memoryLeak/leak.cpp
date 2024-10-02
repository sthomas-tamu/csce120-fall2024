// Can you locate the 3 places where memory is leaked?

int createInteger() {
    int* z = new int(15);
    return *z;
}

int main() {
    int* k = new int(3);

    k = new int (7);

    int w = createInteger();

    return 0;
}

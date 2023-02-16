#ifndef SRC_D
#define SRC_D

struct door {
    int id;
    int status;
};
void initialize_doors(struct door* doors);
void sort(struct door* doors);
void close(struct door* doors);
void output(struct door* doors);

#endif

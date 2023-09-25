#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

/* the main function of threads */
static void * thread_main(void * p_arg)
{
    // TODO

    if (((thread_arg_t*)p_arg)->id == 1){
        for (unsigned int i = 0; i < ((thread_arg_t*)p_arg)->m->nrows / 2; i++)
            for (unsigned int j = 0; j < ((thread_arg_t*)p_arg)->m->ncols; j++)
                ((thread_arg_t*)p_arg)->t->data[i][j] = ((thread_arg_t*)p_arg)->m->data[i][j] + ((thread_arg_t*)p_arg)->n->data[i][j];
    }

    else if (((thread_arg_t*)p_arg)->id == 2){
        for (unsigned int i = ((thread_arg_t*)p_arg)->m->nrows / 2; i < ((thread_arg_t*)p_arg)->m->nrows; i++)
            for (unsigned int j = 0; j < ((thread_arg_t*)p_arg)->m->ncols; j++)
                ((thread_arg_t*)p_arg)->t->data[i][j] = ((thread_arg_t*)p_arg)->m->data[i][j] + ((thread_arg_t*)p_arg)->n->data[i][j];
    }

    return NULL;
}

/* Return the sum of two matrices. The result is in a newly creaed matrix. 
 *
 * If a pthread function fails, report error and exit. 
 * Return NULL if something else is wrong.
 *
 * Similar to addMatrix, but this function uses 2 threads.
 */
TMatrix * addMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->nrows != n->nrows || m->ncols != n->ncols )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, m->ncols);
    if (t == NULL)
        return t;

    // TODO
    thread_arg_t matrix1;
    matrix1.id = 1;
    matrix1.m = m;
    matrix1.n = n;
    matrix1.t = t;

    thread_arg_t matrix2;
    matrix2.id = 2;
    matrix2.m = m;
    matrix2.n = n;
    matrix2.t = t;

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, thread_main, &matrix1);
    pthread_create(&tid2, NULL, thread_main, &matrix2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    

    return matrix1.t;
}
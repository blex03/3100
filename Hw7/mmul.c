#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{
    // TODO
    
    if (((thread_arg_t*)p_arg)->id == 1){
        for (unsigned int i = 0; i < ((thread_arg_t*)p_arg)->m->nrows / 2; i++)  {
            for (unsigned int j = 0; j < ((thread_arg_t*)p_arg)->n->ncols; j++) {
                TElement sum = (TElement)0;
                for (unsigned int k = 0; k < ((thread_arg_t*)p_arg)->m->ncols; k++)
                    sum += ((thread_arg_t*)p_arg)->m->data[i][k] * ((thread_arg_t*)p_arg)->n->data[k][j];
                ((thread_arg_t*)p_arg)->t->data[i][j] = sum;
            }
        }
    }

    else if (((thread_arg_t*)p_arg)->id == 2){
        for (unsigned int i = ((thread_arg_t*)p_arg)->m->nrows / 2; i < ((thread_arg_t*)p_arg)->m->nrows; i++)  {
            for (unsigned int j = 0; j < ((thread_arg_t*)p_arg)->n->ncols; j++) {
                TElement sum = (TElement)0;
                for (unsigned int k = 0; k < ((thread_arg_t*)p_arg)->m->ncols; k++)
                    sum += ((thread_arg_t*)p_arg)->m->data[i][k] * ((thread_arg_t*)p_arg)->n->data[k][j];
                ((thread_arg_t*)p_arg)->t->data[i][j] = sum;
            }
        }
    }

    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

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


    // TODO
    return t;
}
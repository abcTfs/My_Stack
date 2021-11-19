FILE* LOGFILE = fopen("LOGFILE_FOR_STACK.txt", "w+");

enum stack_error_codes
{
    NULL_POINTER_OF_STACK = -999,
    WRONG_CL              = -998,
    WRONG_CR              = -997,
    WRONG_DCL             = -996,
    WRONG_DCR             = -995,
    WRONG_HASH            = -994,
    WRONG_SIZE            = -993,
    NULL_POINTER_OF_DATA  = -992,
};

void stackdump(int statusOfVerification, stack* stk)
{
    switch (statusOfVerification)
    {
    case NULL_POINTER_OF_STACK:
        fprintf(LOGFILE, "Error: WRONG POINTER OF STACK \n\n");
        break;
    case WRONG_CL:
        fprintf(LOGFILE, "Error: WRONG STACK CANARY 1 \n\n");
        break;
    case WRONG_CR:
        fprintf(LOGFILE, "Error: WRONG STACK CANARY 2 \n\n");
        break;
    case WRONG_DCL:
        fprintf(LOGFILE, "Error: WRONG DATA CANARY 1 \n\n");
        break;
    case WRONG_DCR:
        fprintf(LOGFILE, "Error: WRONG DATA CANARY 2 \n\n");
        break;
    case WRONG_HASH:
        fprintf(LOGFILE, "Error: WRONG HASH \nLOGFILE\n");
        break;
    case WRONG_SIZE:
        fprintf(LOGFILE, "Error: WRONG SIZE \n\n");
        break;
    default:
        fprintf(LOGFILE, "NO ERRORS \n\n");
    }

    fprintf(LOGFILE, "THE POINTER OF STACK: %p \n", stk);

    fprintf(LOGFILE, "CAPACITY: %d \n", stk->capacity);

    fprintf(LOGFILE, "SIZE: %d \n", stk->size);

    fprintf(LOGFILE, "Stack canaries: \n");
    fprintf(LOGFILE, "First - %X", stk -> stcannaryL);
    fprintf(LOGFILE, "(%p); should be: DEADDEAD \n", &(stk -> stcannaryL));
    fprintf(LOGFILE, "Second - %X", stk -> stcannaryR);
    fprintf(LOGFILE, "(%p); should be: DEADDEAD \n \n", &(stk -> stcannaryR));

    fprintf(LOGFILE, "Data canaries: \n");
    fprintf(LOGFILE, "1st data canary - %lf (%p); Should be: FEED\n", stk -> data[0], &(stk -> data[0]));
    fprintf(LOGFILE, "2nd data canary - %lf (%p); Should be: FEED\n \n", stk -> data[stk -> capacity + 1], &(stk -> data[stk -> capacity+1]));

    fileprintstk(stk);
}

int verificator(stack* stk)
{
    int statusOfVerification = 0;

    if (stk == NULL)
    {
    statusOfVerification = NULL_POINTER_OF_STACK;
    printf ("There is a mistake on this stage. (Check LOGFILE)\n");
    stackdump(statusOfVerification, stk);
    exit(0);
    }

    else if (stk -> data == NULL)
    {
    statusOfVerification = NULL_POINTER_OF_DATA;
    printf ("There is a mistake on this stage. (Check LOGFILE)\n");
    stackdump(statusOfVerification, stk);
    exit(0);
    }

    else if (stk -> stcannaryL != STCANARY)
    {
    statusOfVerification = WRONG_CL;
    printf ("There is a mistake on this stage. (Check logfile)\n");
    stackdump(statusOfVerification, stk);
    exit(0);
    }

    else if (stk -> stcannaryR != STCANARY)
    {
    statusOfVerification = WRONG_CR;
    printf ("There is a mistake on this stage. (Check LOGFILE)\n");
    stackdump(statusOfVerification, stk);
    exit(0);
    }

    else if (is_Equal(stk -> data[0], (data_t) DATACANARY) == 0)
    {
    statusOfVerification = WRONG_DCL;
    printf ("There is a mistake on this stage. (Check LOGFILE)\n");
    stackdump(statusOfVerification, stk);
    exit(0);
    }

    else if (is_Equal(stk -> data[stk->capacity + 1], (data_t) DATACANARY) == 0)
    {
    statusOfVerification = WRONG_DCR;
    printf ("There is a mistake on this stage. (Check LOGFILE)\n");
    stackdump(statusOfVerification, stk);
    exit(0);
    }

    else if (stk->size > stk->capacity + 1)
    {
    statusOfVerification = WRONG_SIZE;
    printf ("There is a mistake on this stage. (Check LOGFILE)\n");
    stackdump(statusOfVerification, stk);
    exit(0);
    }

    return 0;
}


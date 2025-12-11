#include <stdio.h>
#include "INTERFACE.h"
/* ================= UART & COMMON ================= */

void UART_INITIALIZE(void)
{
    // 實際上你可能會改成初始化 UART 的程式碼
    printf("UART_INITIALIZE()\n");
}

void START_OUTPUT(void)
{
    printf("====================================\n");
    printf("              GAME START            \n");
    printf("====================================\n");
}

/* ================= HINT_OUTPUT ================= */

void HINT_OUTPUT(HINT_OUTPUT_TABLE HO_TABLE)
{
    printf("---------- HINT_OUTPUT ----------\n");
    printf("GAME_STATE   : %d\n", HO_TABLE.GAME_STATE);
    printf("P1_PREPARE   : %d\n", HO_TABLE.P1_PREPARE);
    printf("P2_PREPARE   : %d\n", HO_TABLE.P2_PREPARE);
    printf("---------------------------------\n");
}

/* ================= TTT_OUTPUT ================= */

static char ttt_cell_to_char(int v)
{
    // 依你註解：0 is O, 1 is X, -1 is non-fill
    if (v == 0) return 'O';
    if (v == 1) return 'X';
    return ' ';  // -1 或其他就顯示空白
}

void TTT_OUTPUT(TTT_OUTPUT_TABLE TTTO_TABLE)
{
    printf("---------- TTT_OUTPUT ----------\n");
    printf("CURPLAYER  : %d\n", TTTO_TABLE.CURPLAYER);
    printf("DETWINNER  : %d\n", TTTO_TABLE.DETWINNER);
    printf("SUCCESS    : %d\n", TTTO_TABLE.SUCCESS);
    printf("CURSOR     : %d\n", TTTO_TABLE.CURSOR);
    printf("BOARD (TicTacToe 0~8):\n");

    // 顯示索引
    printf("Index:   0   1   2\n");
    printf("         3   4   5\n");
    printf("         6   7   8\n\n");

    // 顯示 O/X/空白 的棋盤
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int idx = row * 3 + col; // 0,1,2 / 3,4,5 / 6,7,8
            char c = ttt_cell_to_char(TTTO_TABLE.BOARD[idx]);
            printf(" %c ", c);
            if (col < 2) printf("|");
        }
        printf("\n");
        if (row < 2) printf("---+---+---\n");
    }

    printf("---------------------------------\n");
}

/* ================= REACTION_OUTPUT ================= */

void REACTION_OUTPUT(REACTION_OUTPUT_TABLE REACTO_TABLE)
{
    printf("------- REACTION_OUTPUT -------\n");
    printf("RANDOM_NUMBER     : %d\n", REACTO_TABLE.RANDOM_NUMBER);
    printf("DISPLAY_NUMBER_1  : %d\n", REACTO_TABLE.DISPLAY_NUMBER_1);
    printf("DISPLAY_NUMBER_2  : %d\n", REACTO_TABLE.DISPLAY_NUMBER_2);
    printf("P1_RESULT         : %d\n", REACTO_TABLE.P1_RESULT);
    printf("P2_RESULT         : %d\n", REACTO_TABLE.P2_RESULT);
    printf("WINNER            : %d\n", REACTO_TABLE.WINNER);
    printf("tick100us         : %lu\n", REACTO_TABLE.tick100us);
    printf("PLAYER1_STATE     : %d\n", REACTO_TABLE.PLAYER1_STATE);
    printf("PLAYER2_STATE     : %d\n", REACTO_TABLE.PLAYER2_STATE);
    printf("---------------------------------\n");
}

/* ================= WHAC_A_MOLE_OUTPUT ================= */

void WHAC_A_MOLE_OUTPUT(WHAC_A_MOLE_OUTPUT_TABLE WAWO_TABLE)
{
    printf("------ WHAC_A_MOLE_OUTPUT ------\n");
    printf("SCORE_P1           : %d\n", WAWO_TABLE.SCORE_P1);
    printf("SCORE_P2           : %d\n", WAWO_TABLE.SCORE_P2);
    printf("INPUT              : %c\n", WAWO_TABLE.INPUT);
    printf("HIT                : %d\n", WAWO_TABLE.HIT);
    printf("MISS               : %d\n", WAWO_TABLE.MISS);
    printf("NOT_HIT_NOT_MISS   : %d\n", WAWO_TABLE.NOT_HIT_NOT_MISS);
    printf("REMAINING_TIME     : %ld\n", WAWO_TABLE.REMAINING_TIME);
    printf("WINNER             : %d\n", WAWO_TABLE.WINNER);
    printf("tick100us          : %lu\n", WAWO_TABLE.tick100us);
    printf("PLAYER1_STATE      : %d\n", WAWO_TABLE.PLAYER1_STATE);
    printf("PLAYER2_STATE      : %d\n", WAWO_TABLE.PLAYER2_STATE);

    printf("\nWHAC_A_MOLE[9] (layout 7 8 9 / 4 5 6 / 1 2 3):\n");

    /*
        陣列 index 與顯示的對應關係：
        index: 6 7 8  -> 顯示位置 7 8 9 (上排)
        index: 3 4 5  -> 顯示位置 4 5 6 (中排)
        index: 0 1 2  -> 顯示位置 1 2 3 (下排)
    */
    int idx_map[9] = {6, 7, 8, 3, 4, 5, 0, 1, 2};

    // 先印 index 排列說明
    printf("Index layout:\n");
    printf(" 6   7   8  (=> 7 8 9)\n");
    printf(" 3   4   5  (=> 4 5 6)\n");
    printf(" 0   1   2  (=> 1 2 3)\n\n");

    // 真正印出 WHAC_A_MOLE 的值 (照 7 8 9 / 4 5 6 / 1 2 3 的視覺順序)
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int idx = idx_map[row * 3 + col];
            printf(" %2d ", WAWO_TABLE.WHAC_A_MOLE[idx]);
        }
        printf("\n");
    }

    printf("---------------------------------\n");
}

/* ================= END_OUTPUT ================= */

void END_OUTPUT(END_OUTPUT_TABLE EO_TABLE)
{
    printf("---------- END_OUTPUT ----------\n");
    printf("WHO_WIN        : %d\n", EO_TABLE.WHO_WIN);
    printf("P1_WIN_AMOUNT  : %d\n", EO_TABLE.P1_WIN_AMOUNT);
    printf("P2_WIN_AMOUNT  : %d\n", EO_TABLE.P2_WIN_AMOUNT);
    printf("---------------------------------\n");
}

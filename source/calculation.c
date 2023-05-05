#include "calculation.h"

double calculation(Deque *rpn, double x) {
  INC_F_1ARG;
  INC_F_2ARG;
  int op;
  double result, t_1, t_2;
  const char *n_f_2arg = "+-*/A^";
  const char *n_f_1arg = "CDEFGHIJKL";
  Deque *stack = init_deque();
  lexeme_t *t_l = rpn->head;
  while (t_l) {
    if (l_get_type_f(t_l) == VARIABLE) {
      d_push_f(stack, NUMBER, x);
    } else if (l_get_number_f(t_l, &t_1)) {
      d_push_f(stack, NUMBER, t_1);
    } else if (l_get_operation_f(t_l, &op)) {
      if (strchr(n_f_2arg, op)) {
        if (d_get_number_f(stack, &t_2)) free(d_pop_lexem_f(stack));
        if (d_get_number_f(stack, &t_1)) free(d_pop_lexem_f(stack));
        result = f_2arg[strchr(n_f_2arg, op) - n_f_2arg](t_1, t_2);
        d_push_f(stack, NUMBER, result);
      } else if (strchr(n_f_1arg, op)) {
        if (d_get_number_f(stack, &t_1)) free(d_pop_lexem_f(stack));
        result = f_1arg[strchr(n_f_1arg, op) - n_f_1arg](t_1);
        d_push_f(stack, NUMBER, result);
      }
    }
    t_l = t_l->next;
  }
  d_get_number_f(stack, &result);
  d_free(stack);
  free(stack);
  return result;
}

double c_add(double a, double b) { return a + b; }

double c_sub(double a, double b) { return a - b; }

double c_mul(double a, double b) { return a * b; }

double c_div(double a, double b) { return a / b; }

double c_usub(double a) { return -a; }

bool l_get_number_f(lexeme_t *lexeme, double *value) {
  bool flag = false;
  if (l_get_type_f(lexeme) == NUMBER) {
    *value = lexeme->token.number;
    flag = true;
  }
  return flag;
}

bool l_get_operation_f(lexeme_t *lexeme, int *value) {
  bool flag = false;
  if (l_get_type_f(lexeme) == OPERATION) {
    *value = lexeme->token.operation;
    flag = true;
  }
  return flag;
}

int l_get_type_f(lexeme_t *lexeme) { return lexeme ? (int)lexeme->type : -1; }

#ifndef SAIDA__H
#define SAIDA__H

int expandir_saida(Saida exp, int loc_linha, int loc_coluna);
int adicionar_saida_conjunto(int loc_linha, int loc_coluna);
int calcular_pisos_estaticos();
int calcular_piso_geral();
void desalocar_saidas();

#endif
#include "platform_info.h"
#include "ervp_assert.h"
#include "ervp_printf.h"
#include "ervp_matrix_op_sw.h"

#include "ip_instance_info.h"
#include "dca_matrix_mac.h"

static const int PRINT_DCA_MATRIX_MAC_FUNCTION = 0;

ervp_hwtask_busy_fx_t i_dca_matrix_mac00_add(ervp_mop_mapping_t *mop_mapping, const ErvpMatrixInfo *ma_info, const ErvpMatrixInfo *mb_info, ErvpMatrixInfo *mc_info, unsigned int options)
{
  if (PRINT_DCA_MATRIX_MAC_FUNCTION)
    printf_function();
  return dca_matrix_add(mop_mapping, i_dca_matrix_mac00_info, ma_info, mb_info, mc_info, options);
}

ervp_hwtask_busy_fx_t i_dca_matrix_mac00_sub(ervp_mop_mapping_t *mop_mapping, const ErvpMatrixInfo *ma_info, const ErvpMatrixInfo *mb_info, ErvpMatrixInfo *mc_info, unsigned int options)
{
  if (PRINT_DCA_MATRIX_MAC_FUNCTION)
    printf_function();
  return dca_matrix_sub(mop_mapping, i_dca_matrix_mac00_info, ma_info, mb_info, mc_info, options);
}

ervp_hwtask_busy_fx_t i_dca_matrix_mac00_ewmult(ervp_mop_mapping_t *mop_mapping, const ErvpMatrixInfo *ma_info, const ErvpMatrixInfo *mb_info, ErvpMatrixInfo *mc_info, unsigned int options)
{
  if (PRINT_DCA_MATRIX_MAC_FUNCTION)
    printf_function();
  return dca_matrix_ewmult(mop_mapping, i_dca_matrix_mac00_info, ma_info, mb_info, mc_info, options);
}

ervp_hwtask_busy_fx_t i_dca_matrix_mac00_mult(ervp_mop_mapping_t *mop_mapping, const ErvpMatrixInfo *ma_info, const ErvpMatrixInfo *mb_info, ErvpMatrixInfo *mc_info, unsigned int options)
{
  if (PRINT_DCA_MATRIX_MAC_FUNCTION)
    printf_function();
  return dca_matrix_mult(mop_mapping, i_dca_matrix_mac00_info, ma_info, mb_info, mc_info, options);
}

void mop_use_dca_matrix_mac(ervp_mop_mapping_t *mop_mapping)
{
  assert(mop_mapping != NULL);
  mop_mapping->matrix_add = i_dca_matrix_mac00_add;
  mop_mapping->matrix_sub = i_dca_matrix_mac00_sub;
  mop_mapping->matrix_ewmult = i_dca_matrix_mac00_ewmult;
  mop_mapping->matrix_mult = i_dca_matrix_mac00_mult;
}

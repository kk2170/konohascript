	{"HALT", OPCODE_HALT},
	{"THCODE", OPCODE_THCODE},
	{"ENTER", OPCODE_ENTER},
	{"VEXEC", OPCODE_VEXEC},
	{"YIELD", OPCODE_YIELD},
	{"FUNCCALL", OPCODE_FUNCCALL},
	{"TRY", OPCODE_TRY},
	{"TRYEND", OPCODE_TRYEND},
	{"THROW", OPCODE_THROW},
	{"ASSERT", OPCODE_ASSERT},
	{"CATCH", OPCODE_CATCH},
	{"CHKIN", OPCODE_CHKIN},
	{"CHKOUT", OPCODE_CHKOUT},
	{"ERROR", OPCODE_ERROR},
	{"P", OPCODE_P},
	{"PROBE", OPCODE_PROBE},
	{"EXIT", OPCODE_EXIT},
	{"NSET", OPCODE_NSET},
	{"NMOV", OPCODE_NMOV},
	{"NNMOV", OPCODE_NNMOV},
	{"NSET2", OPCODE_NSET2},
	{"NSET3", OPCODE_NSET3},
	{"NSET4", OPCODE_NSET4},
	{"NMOVx", OPCODE_NMOVx},
	{"XNSET", OPCODE_XNSET},
	{"XNMOV", OPCODE_XNMOV},
	{"XNMOVx", OPCODE_XNMOVx},
	{"bNUL", OPCODE_bNUL},
	{"bNN", OPCODE_bNN},
	{"bNOT", OPCODE_bNOT},
	{"iINC", OPCODE_iINC},
	{"iDEC", OPCODE_iDEC},
	{"iNEG", OPCODE_iNEG},
	{"fNEG", OPCODE_fNEG},
	{"iTR", OPCODE_iTR},
	{"fTR", OPCODE_fTR},
	{"iADD", OPCODE_iADD},
	{"iSUB", OPCODE_iSUB},
	{"iMUL", OPCODE_iMUL},
	{"iDIV", OPCODE_iDIV},
	{"iMOD", OPCODE_iMOD},
	{"iEQ", OPCODE_iEQ},
	{"iNEQ", OPCODE_iNEQ},
	{"iLT", OPCODE_iLT},
	{"iLTE", OPCODE_iLTE},
	{"iGT", OPCODE_iGT},
	{"iGTE", OPCODE_iGTE},
	{"iAND", OPCODE_iAND},
	{"iOR", OPCODE_iOR},
	{"iXOR", OPCODE_iXOR},
	{"iLSFT", OPCODE_iLSFT},
	{"iRSFT", OPCODE_iRSFT},
	{"iADDC", OPCODE_iADDC},
	{"iSUBC", OPCODE_iSUBC},
	{"iMULC", OPCODE_iMULC},
	{"iDIVC", OPCODE_iDIVC},
	{"iMODC", OPCODE_iMODC},
	{"iEQC", OPCODE_iEQC},
	{"iNEQC", OPCODE_iNEQC},
	{"iLTC", OPCODE_iLTC},
	{"iLTEC", OPCODE_iLTEC},
	{"iGTC", OPCODE_iGTC},
	{"iGTEC", OPCODE_iGTEC},
	{"iANDC", OPCODE_iANDC},
	{"iORC", OPCODE_iORC},
	{"iXORC", OPCODE_iXORC},
	{"iLSFTC", OPCODE_iLSFTC},
	{"iRSFTC", OPCODE_iRSFTC},
	{"fADD", OPCODE_fADD},
	{"fSUB", OPCODE_fSUB},
	{"fMUL", OPCODE_fMUL},
	{"fDIV", OPCODE_fDIV},
	{"fEQ", OPCODE_fEQ},
	{"fNEQ", OPCODE_fNEQ},
	{"fLT", OPCODE_fLT},
	{"fLTE", OPCODE_fLTE},
	{"fGT", OPCODE_fGT},
	{"fGTE", OPCODE_fGTE},
	{"fADDC", OPCODE_fADDC},
	{"fSUBC", OPCODE_fSUBC},
	{"fMULC", OPCODE_fMULC},
	{"fDIVC", OPCODE_fDIVC},
	{"fEQC", OPCODE_fEQC},
	{"fNEQC", OPCODE_fNEQC},
	{"fLTC", OPCODE_fLTC},
	{"fLTEC", OPCODE_fLTEC},
	{"fGTC", OPCODE_fGTC},
	{"fGTEC", OPCODE_fGTEC},
	{"RCINC", OPCODE_RCINC},
	{"RCDEC", OPCODE_RCDEC},
	{"OSET", OPCODE_OSET},
	{"OMOV", OPCODE_OMOV},
	{"OOMOV", OPCODE_OOMOV},
	{"ONMOV", OPCODE_ONMOV},
	{"OSET2", OPCODE_OSET2},
	{"OSET3", OPCODE_OSET3},
	{"OSET4", OPCODE_OSET4},
	{"RCINCx", OPCODE_RCINCx},
	{"RCDECx", OPCODE_RCDECx},
	{"OMOVx", OPCODE_OMOVx},
	{"XMOV", OPCODE_XMOV},
	{"XOSET", OPCODE_XOSET},
	{"XMOVx", OPCODE_XMOVx},
	{"CHKSTACK", OPCODE_CHKSTACK},
	{"LDMTD", OPCODE_LDMTD},
	{"CALL", OPCODE_CALL},
	{"SCALL", OPCODE_SCALL},
	{"VCALL", OPCODE_VCALL},
	{"VCALL_", OPCODE_VCALL_},
	{"FASTCALL0", OPCODE_FASTCALL0},
	{"RET", OPCODE_RET},
	{"TR", OPCODE_TR},
	{"SCAST", OPCODE_SCAST},
	{"TCAST", OPCODE_TCAST},
	{"ACAST", OPCODE_ACAST},
	{"iCAST", OPCODE_iCAST},
	{"fCAST", OPCODE_fCAST},
	{"JMP", OPCODE_JMP},
	{"JMP_", OPCODE_JMP_},
	{"JMPF", OPCODE_JMPF},
	{"NEXT", OPCODE_NEXT},
	{"BGETIDX", OPCODE_BGETIDX},
	{"BSETIDX", OPCODE_BSETIDX},
	{"BGETIDXC", OPCODE_BGETIDXC},
	{"BSETIDXC", OPCODE_BSETIDXC},
	{"NGETIDX", OPCODE_NGETIDX},
	{"NSETIDX", OPCODE_NSETIDX},
	{"NGETIDXC", OPCODE_NGETIDXC},
	{"NSETIDXC", OPCODE_NSETIDXC},
	{"OGETIDX", OPCODE_OGETIDX},
	{"OSETIDX", OPCODE_OSETIDX},
	{"OGETIDXC", OPCODE_OGETIDXC},
	{"OSETIDXC", OPCODE_OSETIDXC},
	{"bJNUL", OPCODE_bJNUL},
	{"bJNN", OPCODE_bJNN},
	{"bJNOT", OPCODE_bJNOT},
	{"iJEQ", OPCODE_iJEQ},
	{"iJNEQ", OPCODE_iJNEQ},
	{"iJLT", OPCODE_iJLT},
	{"iJLTE", OPCODE_iJLTE},
	{"iJGT", OPCODE_iJGT},
	{"iJGTE", OPCODE_iJGTE},
	{"iJEQC", OPCODE_iJEQC},
	{"iJNEQC", OPCODE_iJNEQC},
	{"iJLTC", OPCODE_iJLTC},
	{"iJLTEC", OPCODE_iJLTEC},
	{"iJGTC", OPCODE_iJGTC},
	{"iJGTEC", OPCODE_iJGTEC},
	{"fJEQ", OPCODE_fJEQ},
	{"fJNEQ", OPCODE_fJNEQ},
	{"fJLT", OPCODE_fJLT},
	{"fJLTE", OPCODE_fJLTE},
	{"fJGT", OPCODE_fJGT},
	{"fJGTE", OPCODE_fJGTE},
	{"fJEQC", OPCODE_fJEQC},
	{"fJNEQC", OPCODE_fJNEQC},
	{"fJLTC", OPCODE_fJLTC},
	{"fJLTEC", OPCODE_fJLTEC},
	{"fJGTC", OPCODE_fJGTC},
	{"fJGTEC", OPCODE_fJGTEC},
	{"CHKIDX", OPCODE_CHKIDX},
	{"CHKIDXC", OPCODE_CHKIDXC},
	{"NOP", OPCODE_NOP},

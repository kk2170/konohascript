String indent;
String space;
String eol;
RUNTIME_DIR=$konoha.package.path + "/konoha.compiler.js/runtime";
String header = "";
if ($env.JS_INCLUDE_RUNTIME == "true") {
    header = """
<html>
<head>
<title>sample</title>
</head>
<script type="text/javascript">
<!--
""";
} else {
    header = """
<html>
<head>
<title>sample</title>
</head>
<script type="text/javascript" language="javascript" src="./konoha.js" > </script>
<script type="text/javascript" language="javascript" src="./js.js" > </script>
<script type="text/javascript" language="javascript" src="./js.dom.js" > </script>
<script type="text/javascript" language="javascript" src="./js.jquery.js" > </script>
<script type='text/javascript' src='jquery-1.7.1.min.js'></script>
<script type="text/javascript" language="javascript" src="./js.math.js" > </script>
<script type="text/javascript" language="javascript" src="./js.websocket.js" > </script>
<script type="text/javascript">
<!--
""";
}
String footer = """
// -->
</script>
<body onload="">
<script type="text/javascript">
<!--
konoha_main();
konoha.printOUT();
// -->
</script>
</body>
</html>
""";
if ($env.JS_USE_WORKER == "true") {
    TOP = "(event)"
} else {
    TOP = "konoha_main()"
}
//class CompilerOpt {
//    int      indentLevel;
//    String   mtdName;
//    String[] packages;
//    String[] source;
//    String[] unexpectedMethods;
//    String[] topLevelFunctionList;
//    String[] protoFunc;
//    String[] errors;
//    String[] useFuncList;
//    String   obfuscatedClassName;
//    Map<String, String> varNameMap;
//    Map<String, String> methodNameMap;
//    Map<String, String> classNameMap;
//}
System.addClassField(CompilerOpt, int     , "indentLevel");
System.addClassField(CompilerOpt, String  , "mtdName");
System.addClassField(CompilerOpt, String[], "packages");
System.addClassField(CompilerOpt, String[], "source");
System.addClassField(CompilerOpt, String[], "unexpectedMethods");
System.addClassField(CompilerOpt, String[], "topLevelFunctionList");
System.addClassField(CompilerOpt, String[], "protoFunc");
System.addClassField(CompilerOpt, String[], "useFuncList");
System.addClassField(CompilerOpt, Map<String, String>, "varNameMap");
System.addClassField(CompilerOpt, Map<String, String>, "methodNameMap");
System.addClassField(CompilerOpt, Map<String, String>, "classNameMap");
@Public void CompilerOpt.init() {
    this.indentLevel = 0;
    this.packages = ["konoha", "js", "js.dom", "js.jquery", "js.math", "js.websocket"];
    this.source = [];
    this.unexpectedMethods = ["isNull"];
    this.topLevelFunctionList = [];
    this.protoFunc = [];
    this.errors = [];
    this.varNameMap = {};
    this.methodNameMap = {};
    this.classNameMap = {};

    this.useFuncList = ((to String)$env.JS_USE_FUNC_LIST).split(",");
    foreach(String str in this.useFuncList) {
        str = str.trim();
    }
}
class JSConfig {
    boolean use_obfuscate;
    boolean gen_html;
    JSConfig() {
        boolean b = "true" == $env.JS_USE_OBFUSCATE;
        boolean c = "true" == $env.JS_GEN_HTML;
        this.use_obfuscate = b;
        this.gen_html = c;
    }
}
JSConfig config = new JSConfig();

@Overload boolean isKonohaClass(String s) {
    return (s.startsWith("konoha") || s.startsWith("js"));
}
@Overload boolean isKonohaClass(Class c) {
    String s = (to String)c;
    return isKonohaClass(s);
}
@Public void Compiler.setIndentLevel(int n) {
    this.opt.indentLevel = n;
}
@Public void Compiler.incIndentLevel() {
    this.opt.indentLevel = this.opt.indentLevel + 1;
}
@Public void Compiler.decIndentLevel() {
    this.opt.indentLevel = this.opt.indentLevel - 1;
}
@Public String K_Inst.declVar(Compiler asm) {
    if (getName() in? asm.opt.varNameMap) {
        return "";
    } else {
        return "var ";
    }
}
@Overload String obfuscateString(int size, int idx, char base, boolean needDoller) {
    int l = 'z' - 'a';
    int i = size, j = idx;
    Bytes b;
    if (needDoller) {
        b = new byte[i+1];
    } else {
        b = new byte[i];
    }
    int m = 0;
    for (int k = (needDoller) ? i : i-1; m < size; k--) {
        b[k] = base + j % (l+1);
        j /= (l+1);
        m++;
    }
    if (i > 1) {
        b[0] = b[0]-1;
    }
    if (needDoller) {
        b[0] = '$';
    }
    return b.decode();
}
@Overload String obfuscateString(int idx, char base, boolean needDoller) {
    int size = 1, j = idx;
    int l = 'Z' - 'A';
    while (j > l) {
        size++;
        j /= (l+1);
    }
    return obfuscateString(size, idx, base, needDoller);
}
@Public @Overload String K_Inst.getVarName(Compiler asm) {
    String s = getName();
    if (asm.opt.varNameMap[s] != null) {
        return asm.opt.varNameMap[s];
    }
    Array<String> keys = asm.opt.varNameMap.keys();
    int i = 1, j, varIdx = |keys|;
    j = varIdx;
    int l = 'Z' - 'A';
    while (j > l) {
        i++;
        j /= (l+1);
    }
    asm.opt.varNameMap.set(s, obfuscateString(i, varIdx, 'a', true));
    return asm.opt.varNameMap[s];
}
@Public void Compiler.setUserClassName(String s) {
    int i = 1, j, classIdx = 0;
    Array<String> keys = opt.classNameMap.keys();
    for (; classIdx < |keys|; classIdx++) {
        if (s == keys[classIdx]) {
            break;
        }
    }
    j = classIdx;
    int l = 'Z' - 'A';
    while (j > l) {
        i++;
        j /= (l+1);
    }
    opt.classNameMap[s] = obfuscateString(i, classIdx, 'A', false);
}
@Public String Compiler.getUserClassName(String s, boolean getOnly) {
    if (opt.classNameMap[s] == null) {
        setUserClassName(s);
    }
    return opt.classNameMap[s];
}
@Public String Compiler.class2str(Class c) {
    String s = (to String)c;
    if (s.endsWith("Script")) {
        return "Script";
    }
    if (s.startsWith("konoha.Array")) {
        return "konoha.Array";
    }   
    if (s.startsWith("konoha.Map")) {
        return "konoha.Map";
    }   
    if (s.startsWith("konoha.Iterator")) {
        return "konoha.Iterator";
    }
    if (s.startsWith("konoha.Func")) {
        return "konoha.Func";
    }
    String[] ary = s.split(".");
    /* TODO class obfuscation */
    //if (c.isPublic() && !isKonohaClass(c)) {
    //    return ary[|ary|-1];
    //}
    if (|ary| >= 2 && isKonohaClass(s)) {
        String res = "";
        for (int i = 0; i < |ary|; i++) {
            res += ary[i];
            if (i != |ary|-1) {
                res += ".";
            }
        }
        return res;
    } else {
        return getUserClassName(ary[|ary|-1]);
    }
}

@Public String Compiler.mtdclass2str(Method m) {
    return class2str(m.getMethodClass());
}
String getTypeName (Class type) {
    String res = (to String) type;
    return (res == "") ? "null" : res;
}
String uscore(String in) {
    //return "__" + in + "__";
    //return "konoha." + in;
    return in;
}

String escape(String str) {
	str = str.replace("\t", "\\t");
	str = str.replace("\n", "\\n");
	return str;
}

String myquote(dynamic value) {
    if(value.class == String) {
        String s = value;
        return  "new konoha.String(\"" + escape(s) + "\")";
    } else if (value.class == Float) {
        Float f = value;
        return f.format("%.20f");
    } else if(((to String)value.class).startsWith("konoha.Array")) {
        int i = value.get(0);
        int size = value.size;
        String res = "[";
        for(int i=0; i<size; i++) {
            if(i != 0) res += ", ";
            res += myquote(value[i]);
        }
        res += "]";
        return "new konoha.Array(" + res + ")";
    } else if(((to String)value.class).startsWith("konoha.Map")) {
        Map m = value;
        String[] keys = m.keys();
        String res = "{";
        for(int i=0; i<|keys|; i++) {
            if(i != 0) res += ", ";
            dynamic o = m[keys[i]];
            res += myquote(keys[i]) + ": " + myquote(o);
        }
        res += "} [";
        for(int i=0; i<|keys|; i++) {
            if(i != 0) res += " ";
            res += m[keys[i]].class;
        }
        res += "]";
        return  "new konoha.Map(" + res + ")";
    } else if (value.class == Method) {
        Method m = (to Method)value;
        return m.getMethodClass() + "." + m.getName();
    } else if (value == null && value.class.isUnboxType()) {
        return "0";
    } else {
        return "" + value;
    }
}
LABEL = "label";
@Public void Compiler.setMethodName(Method mtd) {
    int mtdId = 0;
    Array<Method> mtds = mtd.getMethodClass().getMethods();
    for (; mtdId < |mtds|; mtdId++) {
        if (mtd == mtds[mtdId]) {
            break;
        }
    }
    Class c = mtd.getMethodClass();
    while (!isKonohaClass(c.getSuper())) {
        c = c.getSuper();
        mtdId = mtdId + |c.getMethods()|;
    }
    int i = 1, j = mtdId;
    int l = 'z' - 'a';
    while (j > l) {
        i++;
        j /= (l+1);
    }
    opt.methodNameMap.set(mtd.toString(), obfuscateString(i, mtdId, 'a', false));
}
@Public boolean Compiler.isDecl(Method mtd) {
    return (mtd.toString() in? this.opt.methodNameMap.keys());
}
@Public String Compiler.getMethodName(Method mtd) {
    String s = mtd.toString();
    if (isKonohaClass(mtd.getMethodClass()) && mtd.getMethodClass() != Script) {
        return mtd.getName();
    }
    if (((to String)mtd.getMethodClass()).endsWith("Script") && mtd.getName() == "") {
        int i = 1, j = |this.opt.topLevelFunctionList|;
        int l = 'z' - 'a';
        while (j > l) {
            i++;
            j /= (l+1);
        }
        return "_" + obfuscateString(i, |this.opt.topLevelFunctionList|, 'a', false);
    }
    if (!s in? opt.methodNameMap) {
        setMethodName(mtd);
    }
    return opt.methodNameMap[s];
}
@Public void Compiler.addSource(String str) {
    String tmp = "";
    for (int i = 0; i < opt.indentLevel; i++) {
        tmp += indent;
    }
    tmp += str;
    int size = this.opt.source.size;
    this.opt.source[size - 1] += tmp + eol;
}
@Public void Compiler.addFunc(String init) {
    this.opt.source.add(init);
}

@Public @Override void K_PHI.codegen(Compiler asm) {
    /* if one node incoming, this phinode behave like K_MOV instruction*/
    if (|bbs| == 1) {
        String res;
        res = declVar(asm) + getVarName(asm) + space + "=" + space + insts[0].getVarName(asm) + ";";
        asm.addSource(res);
    }
}
@Public void K_BasicBlock.codegen(Compiler asm) {
    /* do not use */
}

@Public void K_Function.codegen(Compiler asm) {
    boolean flagPrototype = false;
    asm.opt.obfuscatedMethodName = asm.getMethodName(asm.mtd);
    asm.opt.obfuscatedClassName = asm.class2str(asm.mtd.getMethodClass());
    String fncdef = "";
    String thisclass = asm.opt.obfuscatedClassName;
    if (isKonohaClass(asm.mtd.getMethodClass())) {
        flagPrototype = true;
        fncdef += uscore(thisclass) + "." + asm.opt.obfuscatedMethodName + space + "=" + space + "function" + space + "(";
    } else if (isStatic == 1 || ((to String)asm.mtd.getMethodClass()).endsWith("Script")) {
        if (asm.mtd.getName() == "") {
            int size = |asm.opt.topLevelFunctionList|;
            asm.opt.topLevelFunctionList.add(asm.opt.obfuscatedMethodName);
            fncdef += "function " + asm.opt.obfuscatedMethodName + "(";
            //fncdef += "function Script" + size + "(";
            asm.opt.mtdName = asm.opt.obfuscatedMethodName;
        } else if (asm.mtd.getName() == "main") {
            fncdef += "function " + asm.opt.obfuscatedMethodName + "(";
            asm.opt.topLevelFunctionList.add(asm.opt.obfuscatedMethodName);
            asm.opt.mtdName = asm.opt.obfuscatedMethodName;
        } else {
            fncdef += "function " + asm.opt.obfuscatedMethodName + "(";
            asm.opt.mtdName = asm.opt.obfuscatedMethodName;
        }
    } else {
        flagPrototype = true;
        fncdef += uscore(thisclass) + ".prototype." + asm.opt.obfuscatedMethodName + space + "=" + space + "function" + space + "(";
    }
    for (int i = 1 - isStatic; i < |funcargs|; i++) {
        fncdef += funcargs[i].getVarName(asm);
        if (i != |funcargs|-1) {
            fncdef += "," + space;
        }
    }
    fncdef += ") {" + eol;
    asm.addFunc(fncdef);
    asm.setIndentLevel(1);
    if (isStatic == 0 && |funcargs| > 0) {
        asm.addSource("var " + funcargs[0].getVarName(asm) + space + "=" + space + "this;");
    }
    boolean needSwitch = false;
    int count = 0;
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] != null) {
            count++;
            if (count == 2) {
                needSwitch = true;
                break;
            }
        }
    }
    //asm.addSource("'use strict';", 1);
    if (needSwitch) {
        asm.addSource("var " + LABEL + space + "=" + space + "0;");
        asm.addSource("while" + space + "(true)" + space + "{");
        asm.incIndentLevel();
        asm.addSource("switch" + space + "(" + LABEL + ")" + space + "{");
    }
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] == null) continue;
        if (needSwitch) {
            asm.addSource("case " + i + ":");
            asm.incIndentLevel();
        }
        foreach(String s in bbs[i].phis.keys()) {
            bbs[i].phis[s].codegen(asm);
        }
        for (int j = 0; j < |bbs[i].insts|-1; j++) {
            bbs[i].insts[j].codegen(asm);
        }
        for (int j = 0; j < |bbs[i].movs|; j++) {
            bbs[i].movs[j].codegen(asm);
        }
        bbs[i].insts[|bbs[i].insts|-1].codegen(asm);
        if (bbs[i].insts[|bbs[i].insts|-1].class != K_RET) {
          asm.addSource("break;");
        }
        if (needSwitch) {
            asm.decIndentLevel();
        }
    }
    if (needSwitch) {
        asm.addSource("}");
        asm.decIndentLevel();
        asm.addSource("}");
        asm.decIndentLevel();
    }
    asm.decIndentLevel();
    if (flagPrototype) {
        asm.addSource("};");
    } else {
        asm.addSource("}");
    }
}
@Public @Override void K_MOV.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_ADD.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "+" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_SUB.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "-" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_MUL.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "*" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_DIV.codegen(Compiler asm) {
    String res;
    if (this.type == Int) {
        res = declVar(asm) + getVarName(asm) + space + "=" + space + "Math.floor(" + op.inst0.getVarName(asm) + space + "/" + space + op.inst1.getVarName(asm) + ");";
    } else {
        res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "/" + space + op.inst1.getVarName(asm) + ";";
    }
    asm.addSource(res);
}
@Public @Override void K_MOD.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "%" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_EQ.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "==" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_NEQ.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "!=" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_LT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "<" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_GT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + ">" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_LTE.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "<=" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_GTE.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + ">=" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_AND.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "&" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_OR.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "|" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_NOT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=!" + space + op.inst0.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_XOR.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "xor" + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_SELECT.codegen(Compiler asm) {
    String res = "";
    res += declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "?" + space + op.inst1.getVarName(asm) + space + ":" + space + op.inst2.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_LSFT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + "<<" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_RSFT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + space + ">>" + space + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_TCHECK.codegen(Compiler asm) {
    /* do not use */
}
@Public @Override void K_CAST.codegen(Compiler asm) {
    String tcid_str = (to String) op.tcid;
    if (op.scid == Float && op.tcid == Int) {
        asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "Math" + ".floor(" + op.inst0.getVarName(asm) + ");");
    } else if (tcid_str.indexOf("konoha.Iterator") == 0) {
        asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "new " + "konoha.Iterator" + "(" + op.inst0.getVarName(asm) + ");");
    } else if (op.scid == String && op.tcid == Float){
		asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "parseFloat(" + op.inst0.getVarName(asm) + ".rawptr);");
	} else if (op.scid == String && op.tcid == Int) {
		asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "parseInt(" + op.inst0.getVarName(asm) + ".rawptr, 10);");
	} else {
		asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + ";");
    }
}
@Public @Override void K_JMP.codegen(Compiler asm) {
    asm.addSource(LABEL + space + "=" + space + op.jmpidx + ";");
}
@Public @Override void K_COND.codegen(Compiler asm) {
    asm.addSource("if" + space + "(" + op.inst0.getVarName(asm) + ")" + space + "{");
    asm.incIndentLevel();
    asm.addSource(LABEL + space + "=" + space + op.bbThen + ";");
    asm.decIndentLevel();
    asm.addSource("}" + space + "else" + space + "{");
    asm.incIndentLevel();
    asm.addSource(LABEL + space + "=" + space + op.bbElse + ";");
    asm.decIndentLevel();
    asm.addSource("}");
}
@Public void K_CALL.genUnexpectedMethod(Compiler asm) {
    if (op.mtd.getName() == asm.opt.unexpectedMethods[0]) {
        asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + args[0].getVarName(asm) + space + "==" + space + "null;");
    }
}
@Public @Override void K_CALL.codegen(Compiler asm) {
    boolean flag = false;
    if (op.flagStatic == 0) {
        if (!args[0].kvalue.type.isUnboxType()) {
            flag = true;
        }
    }
    if (op.mtd.getName() in? asm.opt.unexpectedMethods) {
        genUnexpectedMethod(asm);
        return;
    }
    String res = "";
    if (op.mtd.getReturnType() != Void) {
        res = declVar(asm) + getVarName(asm) + space + "=" + space;
    }
    String thisclass = asm.mtdclass2str(op.mtd);
    if (flag) {
        res += args[0].getVarName(asm) + ".";
    } else if (thisclass != "Script") {
        res += uscore(thisclass) + ".";
    }
    if (!asm.isDecl(op.mtd) && !isKonohaClass(op.mtd.getMethodClass())) {
        asm.opt.protoFunc.add(asm.getMethodName(op.mtd));
    }
    if (asm.getMethodName(op.mtd) == "new") {
        res += "_new";
    } else {
        res += asm.getMethodName(op.mtd).replace("%s", "send").replace(":", "_");
    }
    res += "(";
    int cur = flag ? 1 : 0;
    for (; cur < |args|; cur++) {
        res += args[cur].getVarName(asm);
        if (cur != |args|-1) {
            res += "," + space;
        }
    }
    res += ");";
    asm.addSource(res);
}
@Public @Override void K_ERR.codegen(Compiler asm) {
    asm.opt.errors.add(op.msg);
	asm.addSource("konoha.THROWN = true;");
    String s = "throw(\"Script!!: " + op.msg + "\");";
    asm.addSource(s);
    return;
}
@Public @Override void K_PRINT.codegen(Compiler asm) {
    int line = (op.opline&((1<<32)-1)<<32)>>32;
    String strline = space;
    String msg = "";
    if (op.msg != "") {
        msg += op.msg + "=";
    }
    asm.addSource("konoha.OUT += \"" + strline + msg + "\"" + space + "+" + space + op.inst0.getVarName(asm) + ".toString()" + space + "+" + space + "\"\\n\";");
}
@Public @Override void K_TR.codegen(Compiler asm) {
    String type_str = (to String)type;
    switch (this.getTRMethod()) {
        case "box":
            asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + ";");
            break;
        case "bnul":
            if (type_str.endsWith("Script")) {
                asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "konoha.script;");
            }
            break;
        case "cwb":
            asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "new konoha.OutputStream(true);");
            break;
        case "tostr":
            asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + ".tostr();");
            break;
        case "chktype":
            asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + ";");
            break;
    }
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    String name = asm.class2str(type);
    asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "new " + uscore(name) + "();");
}
@Public @Override void K_GETIDX.codegen(Compiler asm) {
    asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + ".get(" + op.inst1.getVarName(asm) + ");");
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    asm.addSource(op.inst0.getVarName(asm) + ".set(" + op.inst1.getVarName(asm) + "," + space + op.inst2.getVarName(asm) + ");");
}
@Public @Override void K_CONST.codegen(Compiler asm) {
    //if (op.const_table[op.table_idx].class == Int || op.const_table[op.table_idx].class == Float || op.const_table[op.table_idx].class == Boolean) {
    //    asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + myquote(op.const_table[op.table_idx]) + ";");
    //} else if (op.const_table[op.table_idx].class == Class) {
    //    asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + "new " + uscore("konoha.String") + "(" + myquote(op.const_table[op.table_idx]) + ");");
    //} else {
	Object o = op.const_table[op.table_idx];
	Class c =  op.const_table[op.table_idx].class;
	asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + myquote(o) + ";");
    //}
}
@Public @Override void K_GetField.codegen (Compiler asm) {
    asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + "." + obfuscateString(op.bn, 'a', true) + ";");
}
@Public @Override void K_SetField.codegen(Compiler asm) {
    asm.addSource(op.inst0.getVarName(asm) + "." + obfuscateString(op.an, 'a', true) + space + "=" + space + op.inst1.getVarName(asm) + ";");
}
@Public @Override void K_NEXT.codegen(Compiler asm) {
    asm.addSource(declVar(asm) + getVarName(asm) + space + "=" + space + op.inst0.getVarName(asm) + ".next();");
    asm.addSource("if" + space + "(" + getVarName(asm) + space + "!=" + space + "null)" + space + "{");
    asm.incIndentLevel();
    asm.addSource(LABEL + space + "=" + space + op.nextBB + ";");
    asm.decIndentLevel();
    asm.addSource("}" + space + "else" + space + "{");
    asm.incIndentLevel();
    asm.addSource(LABEL + space + "=" + space + op.endBB + ";");
    asm.decIndentLevel();
    asm.addSource("}");
}
@Public @Override void K_LDMTD.codegen(Compiler asm) {
}
@Public @Override void K_ARGUMENT.codegen(Compiler asm) {
}
@Public @Override void K_RET.codegen(Compiler asm) {
    String res = "return";
    if (asm.retclass != null && op.inst0 != null) {
        res += " " + op.inst0.getVarName(asm);
    }
    res += ";";
    asm.addSource(res);
}

@Public void Compiler.emit(Method mtd) {
    common_emit(mtd);
    kfunc.codegen(this);
}
@Public void Compiler.init(Method mtd) {
    if ($env.JS_USE_INDENT == "true") {
        indent = "    ";
        space = " ";
        eol = EOL;
    } else {
        indent = "";
        space = "";
        eol = "";
    }
    init_common(mtd);
    if (this.opt == null) {
        this.opt = new CompilerOpt();
        this.opt.init();
    }
    this.opt.getVarNameMap = {};
}
@Public String Compiler.createMain() {
    String res = "";
    boolean flagScript = false;
    res += "function Script" + "()" + space + "{" + eol;
    res += "}" + eol;
    res += eol;
    if ($env.JS_USE_WORKER == "true") {
        res += "onmessage = function " + TOP + space + "{" + eol;
        res += indent + "var json" + space + "=" + space + "JSON.parse(event.data);" + eol;
    } else {
        res += "function " + TOP + space + "{" + eol;
    }
    //res += indent + "if (json.type == 'start') {" + eol;
    for (int i = 0; i < this.opt.errors.size; i++) {
        res += indent + "konoha.ERR += \"" + this.opt.errors[i] + "\";" + eol;
    }
    res += indent + "konoha.script = new Script();" + eol;
    foreach (fname in this.opt.topLevelFunctionList) {
        res += indent + fname + "(";
        res += "konoha.script";
        res += ");" + eol;
    }
    if ($env.JS_USE_WORKER == "true") {
        res += indent + "postMessage(JSON.stringify({" + eol;
        res += indent + indent + "'out': konoha.OUT," + eol;
        res += indent + indent + "'err': konoha.ERR," + eol;
        res += indent + indent + "'document': document" + eol;
        res += indent + "}));" + eol;
        res += "};" + eol;
    } else {
        res += "}" + eol;
    }
    return res;
}
@Public String Compiler.createSymbol() {
    String res = "";
    foreach (String symbol in this.opt.useFuncList) {
        String m = "";
        String c = "";
        foreach (String n in this.opt.methodNameMap.keys()) {
            if (n.endsWith(symbol)) {
                m = this.opt.methodNameMap[n];
                if (symbol.indexOf(".") != -1) {
                    c = getUserClassName(symbol.split(".")[0]);
                }
                res += "function " + symbol + "() {" + eol;
                res += indent + "return " + c + ((c == "") ? "" : ".") + m + "();" + eol;
                res += "}" + eol;
            }
        }
    }
    return res;
}
@Public String Compiler.createClassDefinition(Class c, String cname) {
    String res = "";
    if (c.getSuper() != Object) {
        String supcname = class2str(c.getSuper());
        res += uscore(cname) + ".prototype = new " + uscore(supcname) + "()" + eol;
    }
    res += "function " + uscore(cname) + "()" + space + "{" + eol;
    int i = 0;
    foreach (Class fieldclass in c.getFieldClasses()) {
        if (fieldclass.isUnboxType()) {
            res += indent + "this." + obfuscateString(i, 'a', true) + space + "=" + space + "0;";
        } else {
            res += indent + "this." + obfuscateString(i, 'a', true) + space + "=" + space + "null;";
        }
        res += eol;
        i++;
    }
    res += "}" + eol;
    return res;
}
@Public void Compiler.dump(Boolean dump) {
    String output = $script.output;
    OutputStream ous;
    if (output != null) {
        ous = new OutputStream(output);
    } else {
        ous = OUT;
    }
    if ($env.JS_ERROR_OUTPUT == "true") {
        /* return json object
           that contains some information
           of compile error message */
        ous << "{\"error\": ";
        ous << (|opt.errors| > 0) ? "true, " : "false, ";
        ous << "\"stderr\": [";
        for (int i = 0; i < this.opt.errors.size; i++) {
            ous << "\"" + this.opt.errors[i] + "\"";
            if (i != this.opt.errors.size-1) {
                ous << ", ";
            }
        }
		ous << "]}";
    } else {
        if ((config.gen_html) == true) {
            ous << header << eol;
        }
        if ($env.JS_INCLUDE_RUNTIME == "true") {
            foreach (String pkgname in this.opt.packages) {
                InputStream in = new InputStream(RUNTIME_DIR + "/" + pkgname + ".js");
                String tmp = "";
                while ((tmp = in.readLine()) != null) {
                    ous << tmp << eol;
                }
            }
        }
        ous << "'checkpoint'" << eol;
        foreach (String fname in this.opt.protoFunc) {
            ous << "function " + fname + "(){}" << eol;
        }
        foreach (K_Class kc in this.declareclass) {
            String cname = class2str(kc.c);
            ous << createClassDefinition(kc.c, cname) << eol;
        }
        foreach (str in this.opt.source) {
            ous << str << eol;
        }
        ous << createMain() << eol;
        ous << createSymbol();
        if ((config.gen_html) == true) {
            ous << EOL << footer;
        }
    }
    ous.close();
}

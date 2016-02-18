% Generate S-function    
%%%-MATLAB_Construction_Commands_Start
def = legacy_code('initialize');
def.SFunctionName = 'asus_capture_sfcn';
def.OutputFcnSpec = 'asusCapture(uint16 y1[240][320])';
def.StartFcnSpec = 'asusInit()';
def.TerminateFcnSpec = 'asusTerminate()';
def.HeaderFiles = {'asus_capture.h'};
def.IncPaths = {'.\include'};
def.SampleTime = 'parameterized';
def.Options.isMacro = true;
def.Options.useTlcWithAccel = false;
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);
%%%-MATLAB_Construction_Commands_End
     
%%
def = legacy_code('initialize');
def.SFunctionName = 'asus_capture_sfcn';
def.OutputFcnSpec = 'asusCapture(uint16 y1[240][320])';
def.StartFcnSpec = 'asusInit()';
def.TerminateFcnSpec = 'asusTerminate()';
def.HeaderFiles = {'asus_capture.h' 'NI.h' 'wrapper.h'};
def.SourceFiles = {'wrapper.c'};
def.IncPaths = {'.\include'};
def.SrcPaths = {'.\src'};
def.TargetLibFiles = {'libNI.so'};
def.SampleTime = 'parameterized';
def.Options.isMacro = true;
def.Options.useTlcWithAccel = false;
legacy_code('sfcn_tlc_generate', def);
     
%%
legacy_code('rtwmakecfg_generate', def);
%%
%%legacy_code('slblock_generate', def)


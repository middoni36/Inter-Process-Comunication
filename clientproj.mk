##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=clientproj
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/elmehdi/Documents/myclearnworkspace
ProjectPath            :=/home/elmehdi/Documents/myclearnworkspace/clientproj
IntermediateDirectory  :=../build-$(ConfigurationName)/clientproj
OutDir                 :=../build-$(ConfigurationName)/clientproj
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=elmehdi
Date                   :=29/11/21
CodeLitePath           :=/home/elmehdi/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/clientproj/main.c$(ObjectSuffix) ../build-$(ConfigurationName)/clientproj/server.c$(ObjectSuffix) ../build-$(ConfigurationName)/clientproj/pipeline.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/clientproj/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/clientproj"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/clientproj"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/clientproj/.d:
	@mkdir -p "../build-$(ConfigurationName)/clientproj"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/clientproj/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/clientproj/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/elmehdi/Documents/myclearnworkspace/clientproj/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/clientproj/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/clientproj/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/clientproj/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/clientproj/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/clientproj/main.c$(PreprocessSuffix) main.c

../build-$(ConfigurationName)/clientproj/server.c$(ObjectSuffix): server.c ../build-$(ConfigurationName)/clientproj/server.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/elmehdi/Documents/myclearnworkspace/clientproj/server.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/server.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/clientproj/server.c$(DependSuffix): server.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/clientproj/server.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/clientproj/server.c$(DependSuffix) -MM server.c

../build-$(ConfigurationName)/clientproj/server.c$(PreprocessSuffix): server.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/clientproj/server.c$(PreprocessSuffix) server.c

../build-$(ConfigurationName)/clientproj/pipeline.c$(ObjectSuffix): pipeline.c ../build-$(ConfigurationName)/clientproj/pipeline.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/elmehdi/Documents/myclearnworkspace/clientproj/pipeline.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pipeline.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/clientproj/pipeline.c$(DependSuffix): pipeline.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/clientproj/pipeline.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/clientproj/pipeline.c$(DependSuffix) -MM pipeline.c

../build-$(ConfigurationName)/clientproj/pipeline.c$(PreprocessSuffix): pipeline.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/clientproj/pipeline.c$(PreprocessSuffix) pipeline.c


-include ../build-$(ConfigurationName)/clientproj//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)



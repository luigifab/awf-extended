; NSIS installer (v3.11+)
unicode true
!include "MUI2.nsh"
!include "FileFunc.nsh"

!define ENGINE   "gtk2"
!define ARCH     ":ARCH:"
!define ARCHNAME ":ARCHNAME:"
!define VERSION  ":AWFVERSION:"
!define APPNAME  "awf-${ENGINE}"

VIProductVersion "${VERSION}.0"
VIFileVersion    "${VERSION}.0"
VIAddVersionKey  "FileDescription"  "Setup for A widget factory"
VIAddVersionKey  "FileVersion"      "${VERSION}"
VIAddVersionKey  "ProductName"      "A widget factory"
VIAddVersionKey  "ProductVersion"   "${VERSION}"
VIAddVersionKey  "CompanyName"      "luigifab, nullsoft"
VIAddVersionKey  "LegalCopyright"   "2026 Fabrice Creuzot (luigifab), GNU GPL v3"
VIAddVersionKey  "Info1"            "https://github.com/luigifab/awf-extended"
VIAddVersionKey  "Info2"            "https://www.luigifab.fr/gtkqt/awf-extended"
VIAddVersionKey  "Info3"            "https://nsis.sourceforge.io/"
VIAddVersionKey  "InternalName"     "setup-${APPNAME}"
VIAddVersionKey  "OriginalFilename" "setup-${APPNAME}-${VERSION}-${ARCH}.exe"

Name "${APPNAME}"
OutFile "setup-${APPNAME}-${VERSION}-${ARCH}.exe"
InstallDir "$PROGRAMFILES\${APPNAME}"
InstallDirRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "InstallLocation"
RequestExecutionLevel admin

!define MUI_ABORTWARNING
!define MUI_LANGDLL_ALLLANGUAGES
!define MUI_COMPONENTSPAGE_NODESC
!define MUI_LICENSEPAGE_TEXT_TOP ""
!define MUI_ICON "awf-extended-${VERSION}\data\awf.ico"
!define MUI_UNICON "awf-extended-${VERSION}\data\awf.ico"

; Pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "awf-extended-${VERSION}\LICENSE"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

; Languages
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Afrikaans"
!insertmacro MUI_LANGUAGE "Albanian"
!insertmacro MUI_LANGUAGE "Arabic"
!insertmacro MUI_LANGUAGE "Armenian"
!insertmacro MUI_LANGUAGE "Asturian"
!insertmacro MUI_LANGUAGE "Basque"
!insertmacro MUI_LANGUAGE "Belarusian"
!insertmacro MUI_LANGUAGE "Bosnian"
!insertmacro MUI_LANGUAGE "Breton"
!insertmacro MUI_LANGUAGE "Bulgarian"
!insertmacro MUI_LANGUAGE "Catalan"
!insertmacro MUI_LANGUAGE "Corsican"
!insertmacro MUI_LANGUAGE "Croatian"
!insertmacro MUI_LANGUAGE "Czech"
!insertmacro MUI_LANGUAGE "Danish"
!insertmacro MUI_LANGUAGE "Dutch"
!insertmacro MUI_LANGUAGE "Esperanto"
!insertmacro MUI_LANGUAGE "Estonian"
!insertmacro MUI_LANGUAGE "Farsi"
!insertmacro MUI_LANGUAGE "Finnish"
!insertmacro MUI_LANGUAGE "French"
!insertmacro MUI_LANGUAGE "Galician"
!insertmacro MUI_LANGUAGE "Georgian"
!insertmacro MUI_LANGUAGE "German"
!insertmacro MUI_LANGUAGE "Greek"
!insertmacro MUI_LANGUAGE "Hebrew"
!insertmacro MUI_LANGUAGE "Hindi"
!insertmacro MUI_LANGUAGE "Hungarian"
!insertmacro MUI_LANGUAGE "Icelandic"
!insertmacro MUI_LANGUAGE "Indonesian"
!insertmacro MUI_LANGUAGE "Irish"
!insertmacro MUI_LANGUAGE "Italian"
!insertmacro MUI_LANGUAGE "Japanese"
!insertmacro MUI_LANGUAGE "Korean"
!insertmacro MUI_LANGUAGE "Kurdish"
!insertmacro MUI_LANGUAGE "Latvian"
!insertmacro MUI_LANGUAGE "Lithuanian"
!insertmacro MUI_LANGUAGE "Luxembourgish"
!insertmacro MUI_LANGUAGE "Macedonian"
!insertmacro MUI_LANGUAGE "Malay"
!insertmacro MUI_LANGUAGE "Mongolian"
!insertmacro MUI_LANGUAGE "Norwegian"
!insertmacro MUI_LANGUAGE "NorwegianNynorsk"
!insertmacro MUI_LANGUAGE "Pashto"
!insertmacro MUI_LANGUAGE "Polish"
!insertmacro MUI_LANGUAGE "Portuguese"
!insertmacro MUI_LANGUAGE "PortugueseBR"
!insertmacro MUI_LANGUAGE "Romanian"
!insertmacro MUI_LANGUAGE "Russian"
!insertmacro MUI_LANGUAGE "ScotsGaelic"
!insertmacro MUI_LANGUAGE "Serbian"
!insertmacro MUI_LANGUAGE "SerbianLatin"
!insertmacro MUI_LANGUAGE "SimpChinese"
!insertmacro MUI_LANGUAGE "Slovak"
!insertmacro MUI_LANGUAGE "Slovenian"
!insertmacro MUI_LANGUAGE "Spanish"
!insertmacro MUI_LANGUAGE "SpanishInternational"
!insertmacro MUI_LANGUAGE "Swedish"
!insertmacro MUI_LANGUAGE "Tatar"
!insertmacro MUI_LANGUAGE "Thai"
!insertmacro MUI_LANGUAGE "TradChinese"
!insertmacro MUI_LANGUAGE "Turkish"
!insertmacro MUI_LANGUAGE "Ukrainian"
!insertmacro MUI_LANGUAGE "Uzbek"
!insertmacro MUI_LANGUAGE "Vietnamese"
!insertmacro MUI_LANGUAGE "Welsh"
!insertmacro MUI_RESERVEFILE_LANGDLL


; Installer
Function .onInit
	!insertmacro MUI_LANGDLL_DISPLAY

	System::Call 'kernel32::CreateMutex(p 0, i 0, t "${APPNAME}") p .r1 ?e'
	Pop $R0
	StrCmp $R0 0 +3
		MessageBox MB_OK|MB_ICONEXCLAMATION "The installer is already running."
		Abort
FunctionEnd

Function .onVerifyInstDir
	FindFirst $0 $1 "$INSTDIR\*.*"
	loop:
		StrCmp $1 "" done
		StrCmp $1 "." next
		StrCmp $1 ".." next
		FindClose $0
		Abort
	next:
		FindNext $0 $1
		Goto loop
	done:
	FindClose $0
FunctionEnd

Section "AWF - ${VERSION} - ${ARCH} ${ARCHNAME}" SecProgram
	SectionIn RO

	SetOutPath "$INSTDIR"
	File "${ENGINE}\${APPNAME}.exe"

	SetOutPath "$INSTDIR\share\locale\fr\LC_MESSAGES\"
	File /r "${ENGINE}\share\locale\fr\LC_MESSAGES\awf*.mo"

	WriteUninstaller "$INSTDIR\uninstall.exe"

	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayIcon" "$\"$INSTDIR\${APPNAME}.exe,0$\""
	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayName" "${APPNAME} - A widget factory"
	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayVersion" "${VERSION}"
	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "HelpLink" "https://github.com/luigifab/awf-extended"
	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "InstallLocation" "$\"$INSTDIR$\""
	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "Publisher" "luigifab"
	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "QuietUninstallString" "$\"$INSTDIR\uninstall.exe$\" /S"
	WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "UninstallString" "$\"$INSTDIR\uninstall.exe$\""
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "NoModify" 1
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "NoRepair" 1

	${GetSize} "$INSTDIR" "/S=0K" $0 $1 $2
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "EstimatedSize" "$0"
SectionEnd

Section "GTK Core - :ENGINEVERSION: - ${ARCH} ${ARCHNAME}" SecEngine
	SetOutPath "$INSTDIR"
	File    "${ENGINE}\*.dll"
	File /r "${ENGINE}\lib"

	SetOutPath "$INSTDIR\share"
	File /r "${ENGINE}\share\themes"
SectionEnd

Section "GTK Translations" SecTranslations
	SetOutPath "$INSTDIR\share"
	File /r /x "awf*.mo" "${ENGINE}\share\locale"
SectionEnd

Section "Start menu shortcut" SecStartMenu
	SetOutPath "$INSTDIR"
	CreateShortcut "$SMPROGRAMS\${APPNAME}.lnk" "$INSTDIR\${APPNAME}.exe"
SectionEnd

Section "Desktop shortcut" SecDesktop
	SetOutPath "$INSTDIR"
	CreateShortcut "$DESKTOP\${APPNAME}.lnk" "$INSTDIR\${APPNAME}.exe"
SectionEnd

Function .onSelChange
	SectionGetFlags ${SecEngine} $0
	IntOp $0 $0 & ${SF_SELECTED}

	${If} $0 == ${SF_SELECTED}
		!insertmacro ClearSectionFlag ${SecTranslations} ${SF_RO}
	${Else}
		!insertmacro ClearSectionFlag ${SecTranslations} ${SF_SELECTED}
		!insertmacro SetSectionFlag   ${SecTranslations} ${SF_RO}
	${EndIf}
FunctionEnd


; Uninstaller
Section "Uninstall"
	Delete "$SMPROGRAMS\${APPNAME}.lnk"
	Delete "$DESKTOP\${APPNAME}.lnk"
	${If} ${FileExists} "$INSTDIR\${APPNAME}.exe"
	${AndIf} ${FileExists} "$INSTDIR\uninstall.exe"
		RmDir /r "$INSTDIR"
	${EndIf}
	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}"
SectionEnd
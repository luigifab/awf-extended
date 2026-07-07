# Made in ChatGPT and Copilot
# Licensed under the MIT License
_awf_gtk5_complete() {
	local cur prev opts all_opts single_opts
	COMPREPLY=()
	cur="${COMP_WORDS[COMP_CWORD]}"
	prev="${COMP_WORDS[COMP_CWORD-1]}"

	all_opts=(-h --help -v --version -l --list -t --theme -s --screenshot --ltr --rtl)
	single_opts=(-h --help -v --version -l --list)
	declare -A opt_aliases=(
		[-h]=--help
		[--help]=-h
		[-v]=--version
		[--version]=-v
		[-l]=--list
		[--list]=-l
		[-t]=--theme
		[--theme]=-t
		[-s]=--screenshot
		[--screenshot]=-s
		[--rtl]=--ltr
		[--ltr]=--rtl
	)

	case "$prev" in
		-h|--help|-v|--version|-l|--list)
			return 1 # stop
			;;
		-s|--screenshot)
			compopt -o nospace
			COMPREPLY=( $(compgen -d -- "$cur") )
			for i in "${!COMPREPLY[@]}"; do
				COMPREPLY[$i]="${COMPREPLY[$i]}/"
			done
			return 0
			;;
		-t|--theme)
			local themes=$(awf-gtk5 -l 2>/dev/null | awk '{$1=$1};1') # trim + handle list
			COMPREPLY=( $(compgen -W "$themes" -- "$cur") )
			return 0
			;;
	esac

	local used=()
	for ((i = 1; i < COMP_CWORD; i++)); do
		local word="${COMP_WORDS[$i]}"
		if [[ "$word" == -* ]]; then
			used+=("$word")
			[[ -n "${opt_aliases[$word]}" ]] && used+=("${opt_aliases[$word]}")
		fi
	done

	local hide_single_use=false
	for word in "${used[@]}"; do
		case "$word" in
			-t|--theme|-s|--screenshot|--ltr|--rtl)
				hide_single_use=true
				break
				;;
		esac
	done

	local remaining_opts=()
	for opt in "${all_opts[@]}"; do
		local skip=false
		for u in "${used[@]}"; do
			[[ "$opt" == "$u" ]] && skip=true && break
		done
		if $hide_single_use; then
			for su in "${single_opts[@]}"; do
				[[ "$opt" == "$su" ]] && skip=true && break
			done
		fi
		$skip || remaining_opts+=("$opt")
	done

	opts=${remaining_opts[*]}
	COMPREPLY=( $(compgen -W "$opts" -- "$cur") )
}
complete -F _awf_gtk5_complete awf-gtk5
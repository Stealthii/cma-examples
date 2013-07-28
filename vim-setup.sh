#!/usr/bin/env bash


die() { echo "$@"; exit 1; }

test -x "/usr/bin/git" || echo "You need git installed! Running 'sudo apt-get install git'" && sudo apt-get -y install git
test -x "/usr/bin/curl" || echo "You need curl installed! Running 'sudo apt-get install curl'" && sudo apt-get -y install curl
test -x "/usr/bin/vim" || echo "You need vim installed! Running 'sudo apt-get install vim'" && sudo apt-get -y install vim

clear
echo "Welcome to the Capital Markets Academy Vim Improvement package!

This will set up Vim with some basic settings handy for writing Python code,
and install the following plugins:

- pythogen - To manage other Vim plugins
- vim-sensible - To enforce sane default settings for Vim
- pydiction - For autocompleting Python code
- python-mode - PyLint, Rope, Pydoc, breakpoints from box
- Tagbar - For showing structure of source code
- MiniBufExplorer - For showing tabs on multiple files
- vim-pasta - Pasting in Vim with indenting adjusted to destination context
- vcscommand - for integration with many version control systems
- sideways - to move function arguments (and other delimited-by-something
             items) left and right

For more information on these plugins, you should check out their documentation online.

WARNING! Installation will delete any existing Vim setup you have!

Is this ok? (y/n) "
while read yesno; do

    case $yesno in
        y|Y|Yes|yes) break
        ;;
        n|N|No|no) die "Not installing anything!"
        ;;
        *)
        printf "\nPlease enter y or n: "
        ;;
    esac
done

rm -rf $HOME/.vim*
mkdir -p $HOME/.vim/autoload $HOME/.vim/bundle; \

echo "Installing Pathogen..."
curl -Sso $HOME/.vim/autoload/pathogen.vim \
    https://raw.github.com/tpope/vim-pathogen/master/autoload/pathogen.vim

cd $HOME/.vim/bundle

echo "Installing vim-sensible..."
git clone https://github.com/tpope/vim-sensible.git

echo "Installing pydiction..."
git clone https://github.com/rkulla/pydiction.git

echo "Installing python-mode..."
git clone https://github.com/klen/python-mode.git

echo "Installing Tagbar..."
git clone https://github.com/majutsushi/tagbar.git

echo "Installing MiniBufExplorer..."
git clone https://github.com/fholgado/minibufexpl.vim.git

echo "Installing vim-pasta..."
git clone https://github.com/sickill/vim-pasta.git

echo "Installing vcscommand..."
git clone http://repo.or.cz/r/vcscommand.git

echo "Installing sideways..."
git clone https://github.com/AndrewRadev/sideways.vim.git

echo "Writing default .vimrc..."
cat <<EOF > $HOME/.vimrc
syntax enable "Make sure we use syntax highlighting

set hidden "Keeps invisible buffers loaded
set mouse=a "Enables mouse support
set hlsearch "When searching, highlights all matches

set ignorecase "Case insensitive search
set smartcase  "Makes searching case-sensitive if you have a mixed case search
set nostartofline "Keeps the cursor at the same position on a line
set laststatus=2 "Always show the status line
set confirm "Ask for confirmation when changes have happened
set visualbell "Allows Vim to notify you through the terminal
set cmdheight=2 "Sets the command buffer (at bottom) to size 2
set number "Shows line numbers

"The settings below refer to indentation of code.  To simplify:
" - Tabs are replaced with 4 spaces.
" - Indentation is (by default) always 4 spaces
" - If you have only got 8 space indentation, these will become tabs again

set shiftwidth=4 "The automatic indent amount
set tabstop=8 "How many columns relate to a tab
set softtabstop=4 "4 columns when you press tab
set expandtab "This replaces tab with spaces!

"Pathogen
execute pathogen#infect()
execute pathogen#helptags()
filetype plugin indent on

"Pydiction
let g:pydiction_location = '$HOME/.vim/bundle/pydiction/complete-dict'
let g:pydiction_menu_height = 12 "Set autocomplete list to height 12

"python-mode
let g:pymode_folding = 0 "Do NOT fold functions/classes by default
let g:pymode_lint_write = 0 "Disable pylint checking every save
let g:pymode_run_key = 'R' "Set key 'R' for run python code
let g:pymode_rope = 0 "Don't load rope plugin by default

"Tagbar
nmap <F3>      :TagbarToggle <CR>| " F3 Tagbar
vmap <F3> <Esc>:TagbarToggle <CR>
omap <F3> <Esc>:TagbarToggle <CR>
map! <F3> <Esc>:TagbarToggle <CR>

"Sideways
nnoremap <c-h> :SidewaysLeft<cr>
nnoremap <c-l> :SidewaysRight<cr>

"   USING Vim to compare the differences between two files
"   vi -d file1  file2  -- switch cursor to left or right window
nnoremap <S-Left>  <c-w>h   |" move cursor to the left window  (Shift + Left Arrow)
nnoremap <S-Right> <c-w>l   |" move cursor to the right window (Shift + Right Arrow)

"MiniBufExplorer
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapWindowNavArrows = 1
let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplModSelTarget = 1
EOF

echo "

Capital Markets Vim package has been installed!

(Remember to buy Daniel a beer if this script has made your life easier.)

You should have a quick look at the settings that have been created for you in your .vimrc file.
Documentation is available online for all vim settings!

You can do this by typing:

vim ~/.vimrc

Happy coding!"

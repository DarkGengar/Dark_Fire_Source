rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

#---------------------------------------------------------------------------------
# canned command sequence for binary data
#---------------------------------------------------------------------------------
define bin2o
	bin2s $< | $(AS) -o $(@)
	echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' -e 's/[^A-Za-z0-9_]/_/g')`"_end[];" > `(echo $(<F) | tr . _)`.h
	echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' -e 's/[^A-Za-z0-9_]/_/g')`"[];" >> `(echo $(<F) | tr . _)`.h
	echo "extern const u32" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' -e 's/[^A-Za-z0-9_]/_/g')`_size";" >> `(echo $(<F) | tr . _)`.h
endef

# ! type: shell script only use in recipe
# call create-master-header,file_name,header_list,remove?
define create-master-header
	printf "//\n// $(notdir $1)\n//\n\n		\
  			#ifdef __cplusplus\nextern \"C\" {\n#endif" > $1
  	cat $2 >> $1
  	printf "\n#ifdef __cplusplus\n};\n#endif // $(notdir $1)" >> $1
	if [ $3 -eq 1 ];	\
	then				\
		rm -fvr $2;		\
	fi
endef

## if you just want to include the separate headers, use this instead of cat:
#	for hdr in $2 ;	\
#		do echo -e "#include \"$$hdr\"" >> $1 ; done;

# --- odds and ends ---

## Get the title-part of filename.
define title		# $1: filepath
	$(basename $(notdir $1))
endef

## Get a valid C identifier for a name.
define cident		# $1: name
	`echo $1 | sed -e 's|^\([0-9]\)|_\1| ; s|[./\\-]|_|g'`
endef

## Create a header file for a bin2s converted binary.
define bin-header		# $1: path, $2: identifier
	echo "extern const u32 $(strip $2)_size;" >  $1
	echo "extern const u8 $(strip $2)[];"     >> $1	
endef
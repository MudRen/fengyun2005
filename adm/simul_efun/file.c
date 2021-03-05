// file.c
#include <runtime_config.h>
#include <ansi.h>
#define TAIL_LINES 11

varargs string tail(string fname, int nlines)
{
    int chunk, offset, num_nl, p, skip;
    string str = "";

    if(nullp(fname)) error("tail: No file name supplied.");
    if(nullp(nlines) || nlines < 1) nlines = TAIL_LINES;

    chunk = nlines * 80;
    offset = file_size(fname);

    while (offset > 0 && num_nl <= nlines) {
    num_nl = 0;
    offset -= chunk;
    if (offset < 0) {
        chunk += offset; /* negative */
        offset = 0;
    }
    str = read_bytes(fname, offset, chunk) + str;
    p = -1;
    while (p < sizeof(str)-1 && p = member_array('\n', str, p+1))
        num_nl++;
    }
    skip = num_nl - nlines;
    p = -1;
    while (skip--)
    p = member_array('\n', str, p+1);
    return str[p..];
}

void cat(string file)
{
	write(read_file(file));
}

void log_file(string file, string text)
{
	if(file_size(LOG_DIR+file)>500*1024)//如果文件长度>500k
	{
		seteuid(ROOT_UID);
		rename(LOG_DIR+file,sprintf("%s%s.%d",LOG_DIR+"backup/",file,time()));
		seteuid(getuid());
	}
	write_file(LOG_DIR + file, text);
}

void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");
	dir = dir[0..sizeof(dir)-2];
	path = "/";
	for(i=0; i<sizeof(dir); i++) {
		path += dir[i];
		mkdir(path);
		path += "/";
	}
}

string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
}
string color_filter(string content)
{
        if (! content)
                return "";

        // Foreground color
        content = replace_string(content, "$BLK$", BLK);
        content = replace_string(content, "$RED$", RED);
        content = replace_string(content, "$GRN$", GRN);
        content = replace_string(content, "$YEL$", YEL);
        content = replace_string(content, "$BLU$", BLU);
        content = replace_string(content, "$MAG$", MAG);
        content = replace_string(content, "$CYN$", CYN);
        content = replace_string(content, "$WHT$", WHT);
        content = replace_string(content, "$HIR$", HIR);
        content = replace_string(content, "$HIG$", HIG);
        content = replace_string(content, "$HIY$", HIY);
        content = replace_string(content, "$HIB$", HIB);
        content = replace_string(content, "$HIM$", HIM);
        content = replace_string(content, "$HIC$", HIC);
        content = replace_string(content, "$HIW$", HIW);
        content = replace_string(content, "$HIK$", HIK);
        content = replace_string(content, "$NOR$", NOR);

        // Background color
        content = replace_string(content, "$BBLK$", BBLK);
        content = replace_string(content, "$BRED$", BRED);
        content = replace_string(content, "$BGRN$", BGRN);
        content = replace_string(content, "$BYEL$", BYEL);
        content = replace_string(content, "$BBLU$", BBLU);
        content = replace_string(content, "$BMAG$", BMAG);
        content = replace_string(content, "$BCYN$", BCYN);
        content = replace_string(content, "$BWHT$", BWHT);
        content = replace_string(content, "$HBRED$", HBRED);
        content = replace_string(content, "$HBGRN$", HBGRN);
        content = replace_string(content, "$HBYEL$", HBYEL);
        content = replace_string(content, "$HBBLU$", HBBLU);
        content = replace_string(content, "$HBMAG$", HBMAG);
        content = replace_string(content, "$HBCYN$", HBCYN);
        content = replace_string(content, "$HBWHT$", HBWHT);

        content = replace_string(content, "$U$", U);
        content = replace_string(content, "$BLINK$", BLINK);
        content = replace_string(content, "$REV$", REV);
        content = replace_string(content, "$HIREV$", HIREV);
        content = replace_string(content, "$BOLD$", BOLD);

        content = replace_string(content, "$REDGRN$", REDGRN);
        content = replace_string(content, "$REDYEL$", REDYEL);
        content = replace_string(content, "$REDBLU$", REDBLU);
        content = replace_string(content, "$REDMAG$", REDMAG);
        content = replace_string(content, "$REDCYN$", REDCYN);
        content = replace_string(content, "$REDWHI$", REDWHI);
        content = replace_string(content, "$GRNRED$", GRNRED);
        content = replace_string(content, "$GRNYEL$", GRNYEL);
        content = replace_string(content, "$GRNBLU$", GRNBLU);
        content = replace_string(content, "$GRNMAG$", GRNMAG);
        content = replace_string(content, "$GRNCYN$", GRNCYN);
        content = replace_string(content, "$GRNWHI$", GRNWHI);
        content = replace_string(content, "$YELRED$", YELRED);
        content = replace_string(content, "$YELGRN$", YELGRN);
        content = replace_string(content, "$YELBLU$", YELBLU);
        content = replace_string(content, "$YELMAG$", YELMAG);
        content = replace_string(content, "$YELCYN$", YELCYN);
        content = replace_string(content, "$YELWHI$", YELWHI);
        content = replace_string(content, "$BLURED$", BLURED);
        content = replace_string(content, "$BLUGRN$", BLUGRN);
        content = replace_string(content, "$BLUYEL$", BLUYEL);
        content = replace_string(content, "$BLUMAG$", BLUMAG);
        content = replace_string(content, "$BLUCYN$", BLUCYN);
        content = replace_string(content, "$BLUWHI$", BLUWHI);
        content = replace_string(content, "$MAGRED$", MAGRED);
        content = replace_string(content, "$MAGGRN$", MAGGRN);
        content = replace_string(content, "$MAGYEL$", MAGYEL);
        content = replace_string(content, "$MAGBLU$", MAGBLU);
        content = replace_string(content, "$MAGCYN$", MAGCYN);
        content = replace_string(content, "$MAGWHI$", MAGWHI);
        content = replace_string(content, "$CYNRED$", CYNRED);
        content = replace_string(content, "$CYNGRN$", CYNGRN);
        content = replace_string(content, "$CYNYEL$", CYNYEL);
        content = replace_string(content, "$CYNBLU$", CYNBLU);
        content = replace_string(content, "$CYNMAG$", CYNMAG);
        content = replace_string(content, "$CYNWHI$", CYNWHI);
        content = replace_string(content, "$WHIRED$", WHIRED);
        content = replace_string(content, "$WHIGRN$", WHIGRN);
        content = replace_string(content, "$WHIYEL$", WHIYEL);
        content = replace_string(content, "$WHIBLU$", WHIBLU);
        content = replace_string(content, "$WHIMAG$", WHIMAG);
        content = replace_string(content, "$WHICYN$", WHICYN);


        return content;
}

void color_cat(string file)
{
        if( previous_object() )
                seteuid(geteuid(previous_object()));
        else
                seteuid(ROOT_UID);

        write(color_filter(read_file(file)));
}

int file_lines(string file)
{
#ifdef BINARY_SUPPORT
        return efun::file_lines(file);
#else
        int i;
        int jmp;

        i = 65536;
        jmp = i / 2;

        while (jmp) {
                if( read_file(file, i, 1) ) i += jmp; else
                                            i -= jmp;
                jmp /= 2;
        }

        return i - 1;
#endif
}

int is_c_file(string arg)
{
        int l;

        l = strlen(arg);
        if( arg[l - 1] == 'c' && arg[l - 2] == '.' )
                return 1;

        return 0;
}


#define FILE_TYPE       ({ "", ".c", ".o", ".h" })

void intact_file_name(string filename)
{
        if( !filename ) return;

        foreach( string type in FILE_TYPE )
        {
                if( file_size(filename+type) >= 0 )
                {
                        filename += type;
                        break;
                }
        }
}

int file_exists(string filename)
{
        if( !stringp(filename) ) return 0;

        intact_file_name(filename);

        return file_size(filename) > 0;
}



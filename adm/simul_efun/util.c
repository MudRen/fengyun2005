// util.c
#include <localtime.h>
#include <ansi.h>

string process_bar(int n)
{
        string sp;
        int start;

        if( n < 0 ) n = 0; else
        if( n > 100 ) n = 100;

        sp = "                                                  " NOR;
        if( n == 100 ) {
                sp[22] = '1';
                sp[23] = '0';
                sp[24] = '0';
                sp[25] = '%';
                start = 22;
        } else
        if( n >= 10 ) {
                sp[23] = (n / 10) + '0';
                sp[24] = (n % 10) + '0';
                sp[25] = '%';
                start = 23;
        } else {
                sp[24] = n + '0';
                sp[25] = '%';
                start = 24;
        }

        n /= 2;
        if( start > n ) {
                sp = sp[0..start-1] + HIY + sp[start..<0];
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
        } else {
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
                sp = sp[0..start-1] + HIY + sp[start..<0];
        }

        sp = NOR + BCYN + sp;
        return sp;
}

// sort a chinese string (must be chinese), align the
// string with then len. the prefix is used when the desc
// will be lead by another string or space with length is prefix.
string sort_string(string input, int width, int prefix)
{
#ifdef BINARY_SUPPORT
        return efun::sort_string(input, width, prefix);
#else
        int i;
        int sl;
        int len;
        int esc;
        string result;

        result = "";

        len = prefix;
        esc = 0;
        sl = strlen(input);
        for (i = 0; i < sl; i++) {
                if( len >= width && input[i] != '\n' ) {
                        int k;
                        k = i;
                        if( input[i] == 27 )
                                while (k < sl && input[k++] != 'm');

                        switch ((k < sl - 1) ? input[k..k+1] : 0)
                        {
                        case "：":
                        case "”":
                        case "。":
                        case "，":
                        case "；":
                        case "）":
                        case " )":
                        case "！":
                        case "？":
                        case "、":
                                if( k != i ) {
                                        result += input[i..k + 1];
                                        i = k + 1;
                                        continue;
                                }
                                break;
                        default:
                                len = 0;
                                result += "\n";
                                break;
                        }
                }

                if( input[i] == 27 )
                        esc = 1;

                if( ! esc ) {
                        if( input[i] > 160 ) {
                                result += input[i..i+1];
                                i ++;
                                len += 2;
                                continue;
                        }
                        if( input[i] == '\n' ) {
                                result += "\n";
                                len = 0;
                                continue;
                        }
                }

                result += input[i..i];
                if( ! esc ) len++;

                if( esc && input[i] == 'm' )
                        esc = 0;
        }

        if( i < sl )
                result += input[i..sl-1];

        if( len ) result += "\n";

        return result;
#endif
}

#ifndef BINARY_SUPPORT
int binary_valid(string file)
{
        return 1;
}
#endif

object get_object(string name)
{
        object ob;

        if( !name ) return 0;
        if( ob = find_object(name) )
                return ob;

        sscanf(name, "%s#%*s", name);
        return load_object(name);
}

// calculate the color char in a string
int color_len(string str)
{
        int i;
        int extra;

#ifdef LONELY_IMPROVED
        return 0;
#endif
        extra = 0;
        for (i = 0; i < strlen(str); i++) {
                if( str[i] == ESC[0] ) {
                        while ((extra++, str[i] < 'A' ||
                                         str[i] > 'z' ||
                                         str[i] > 'Z' && str[i] < 'a') && i < strlen(str))
                                i++;
                }
        }
        return extra;
}

// to a appromix time
varargs string appromix_time(int n, int flag)
{
        string s;
        string os;
        int odd;
        int bn;

        if( n <= 0 )
                return flag ? "马上就" : "马上";

        bn = 1;
        if( n < bn * 60 ) {
                // bn 单位是秒钟
                s = "秒钟";
                odd = 0;
        } else
        if( bn *= 60, n < bn * 60 ) {
                // bn 单位是分钟
                s = "分钟";
                os = "秒钟";
                odd = n % bn;
                n /= bn;
        } else
        if( bn *= 60, n < 24 * bn ) {
                // bn 单位是小时
                s = "小时";
                os = "分钟";
                odd = (n % bn) / 60;
                n /= bn;
        } else
        if( bn *= 24, n < 30 * bn ) {
                // bn 单位是天
                s = "天";
                os = "小时";
                odd = (n % bn) / (60 * 60);
                n /= bn;
        } else
        if( n < 365 * bn ) {
                // bn 单位是天
                s = "个月";
                os = "天";
                odd = (n % (30 * bn)) / bn;
                n /= 30 * bn;
        } else {
                // bn 单位是天
                s = "年";
                os = "个月";
                odd = (n % (365 * bn)) / (bn * 30);
                n /= 365 * bn;
        }

        s = chinese_number(n) + s;
        if( odd )
                s += "零" + chinese_number(odd) + os;

        if( flag ) s += "以后";
        return s;
}

// filter color
varargs string filter_color(string arg, int raw)
{
        if( !arg ) return "";
#ifdef LONELY_IMPROVED
        return efun::remove_ansi(arg);
#else
        arg = replace_string(arg, BLK, "");
        arg = replace_string(arg, RED, "");
        arg = replace_string(arg, GRN, "");
        arg = replace_string(arg, YEL, "");
        arg = replace_string(arg, BLU, "");
        arg = replace_string(arg, MAG, "");
        arg = replace_string(arg, CYN, "");
        arg = replace_string(arg, WHT, "");
        arg = replace_string(arg, HIR, "");
        arg = replace_string(arg, HIG, "");
        arg = replace_string(arg, HIY, "");
        arg = replace_string(arg, HIB, "");
        arg = replace_string(arg, HIM, "");
        arg = replace_string(arg, HIC, "");
        arg = replace_string(arg, HIW, "");
        arg = replace_string(arg, HIK, "");
        arg = replace_string(arg, NOR, "");
        arg = replace_string(arg, BOLD, "");
        arg = replace_string(arg, BLINK, "");

        if( raw)
        {
                arg = replace_string(arg, BBLK, "");
                arg = replace_string(arg, BRED, "");
                arg = replace_string(arg, BGRN, "");
                arg = replace_string(arg, BYEL, "");
                arg = replace_string(arg, BBLU, "");
                arg = replace_string(arg, BMAG, "");
                arg = replace_string(arg, BCYN, "");
                arg = replace_string(arg, HBRED, "");
                arg = replace_string(arg, HBGRN, "");
                arg = replace_string(arg, HBYEL, "");
                arg = replace_string(arg, HBBLU, "");
                arg = replace_string(arg, HBMAG, "");
                arg = replace_string(arg, HBCYN, "");
                arg = replace_string(arg, HBWHT, "");
                arg = replace_string(arg, REDGRN, "");
                arg = replace_string(arg, REDYEL, "");
                arg = replace_string(arg, REDBLU, "");
                arg = replace_string(arg, REDMAG, "");
                arg = replace_string(arg, REDCYN, "");
                arg = replace_string(arg, REDWHI, "");
                arg = replace_string(arg, GRNRED, "");
                arg = replace_string(arg, GRNYEL, "");
                arg = replace_string(arg, GRNBLU, "");
                arg = replace_string(arg, GRNMAG, "");
                arg = replace_string(arg, GRNCYN, "");
                arg = replace_string(arg, GRNWHI, "");
                arg = replace_string(arg, YELRED, "");
                arg = replace_string(arg, YELGRN, "");
                arg = replace_string(arg, YELBLU, "");
                arg = replace_string(arg, YELMAG, "");
                arg = replace_string(arg, YELCYN, "");
                arg = replace_string(arg, YELWHI, "");
                arg = replace_string(arg, BLURED, "");
                arg = replace_string(arg, BLUGRN, "");
                arg = replace_string(arg, BLUYEL, "");
                arg = replace_string(arg, BLUMAG, "");
                arg = replace_string(arg, BLUCYN, "");
                arg = replace_string(arg, BLUWHI, "");
                arg = replace_string(arg, MAGRED, "");
                arg = replace_string(arg, MAGGRN, "");
                arg = replace_string(arg, MAGYEL, "");
                arg = replace_string(arg, MAGBLU, "");
                arg = replace_string(arg, MAGCYN, "");
                arg = replace_string(arg, MAGWHI, "");
                arg = replace_string(arg, CYNRED, "");
                arg = replace_string(arg, CYNGRN, "");
                arg = replace_string(arg, CYNYEL, "");
                arg = replace_string(arg, CYNBLU, "");
                arg = replace_string(arg, CYNMAG, "");
                arg = replace_string(arg, CYNWHI, "");
                arg = replace_string(arg, WHIRED, "");
                arg = replace_string(arg, WHIGRN, "");
                arg = replace_string(arg, WHIYEL, "");
                arg = replace_string(arg, WHIBLU, "");
                arg = replace_string(arg, WHIMAG, "");
                arg = replace_string(arg, WHICYN, "");
        }
        return arg;
#endif
}

string up_case(string arg)
{
        int i;
        for (i = 0; i < strlen(arg); i++)
                if( arg[i] >= 'a' && arg[i] <= 'z' )
                        arg[i] = arg[i] - 32;
        return arg;
}

// trans_color
// raw = 0, only forecolor
// raw = 1, include backround color
// raw = 2, include blink & others
string trans_color(string arg, int raw)
{
/*
#ifdef LONELY_IMPROVED
        return efun::ansi(arg);
#else
*/
        // forecolor
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$HIK$", HIK);
        arg = replace_string(arg, "$NOR$", NOR);

        if( raw ) {
                // Background color
                arg = replace_string(arg, "$BBLK$", BBLK);
                arg = replace_string(arg, "$BRED$", BRED);
                arg = replace_string(arg, "$BGRN$", BGRN);
                arg = replace_string(arg, "$BYEL$", BYEL);
                arg = replace_string(arg, "$BBLU$", BBLU);
                arg = replace_string(arg, "$BMAG$", BMAG);
                arg = replace_string(arg, "$BCYN$", BCYN);
                arg = replace_string(arg, "$HBRED$", HBRED);
                arg = replace_string(arg, "$HBGRN$", HBGRN);
                arg = replace_string(arg, "$HBYEL$", HBYEL);
                arg = replace_string(arg, "$HBBLU$", HBBLU);
                arg = replace_string(arg, "$HBMAG$", HBMAG);
                arg = replace_string(arg, "$HBCYN$", HBCYN);
                arg = replace_string(arg, "$HBWHT$", HBWHT);
        }

        if( raw == 2 ) {
                // special effect
                arg = replace_string(arg, "$U$", U);
                arg = replace_string(arg, "$BLINK$", BLINK);
                arg = replace_string(arg, "$REV$", REV);
                arg = replace_string(arg, "$HIREV$", HIREV);
                arg = replace_string(arg, "$BOLD$", BOLD);
        }

        if( raw == 3 ) {
                // special effect
                arg = replace_string(arg, "$U$", U);
                arg = replace_string(arg, "$UNDER$", U);
                arg = replace_string(arg, "$BLINK$", BLINK);
                arg = replace_string(arg, "$REV$", REV);
                arg = replace_string(arg, "$HIREV$", HIREV);
                arg = replace_string(arg, "$BOLD$", BOLD);

                arg = replace_string(arg, "$REDGRN$", REDGRN);
                arg = replace_string(arg, "$REDYEL$", REDYEL);
                arg = replace_string(arg, "$REDBLU$", REDBLU);
                arg = replace_string(arg, "$REDMAG$", REDMAG);
                arg = replace_string(arg, "$REDCYN$", REDCYN);
                arg = replace_string(arg, "$REDWHI$", REDWHI);
                arg = replace_string(arg, "$GRNRED$", GRNRED);
                arg = replace_string(arg, "$GRNYEL$", GRNYEL);
                arg = replace_string(arg, "$GRNBLU$", GRNBLU);
                arg = replace_string(arg, "$GRNMAG$", GRNMAG);
                arg = replace_string(arg, "$GRNCYN$", GRNCYN);
                arg = replace_string(arg, "$GRNWHI$", GRNWHI);
                arg = replace_string(arg, "$YELRED$", YELRED);
                arg = replace_string(arg, "$YELGRN$", YELGRN);
                arg = replace_string(arg, "$YELBLU$", YELBLU);
                arg = replace_string(arg, "$YELMAG$", YELMAG);
                arg = replace_string(arg, "$YELCYN$", YELCYN);
                arg = replace_string(arg, "$YELWHI$", YELWHI);
                arg = replace_string(arg, "$BLURED$", BLURED);
                arg = replace_string(arg, "$BLUGRN$", BLUGRN);
                arg = replace_string(arg, "$BLUYEL$", BLUYEL);
                arg = replace_string(arg, "$BLUMAG$", BLUMAG);
                arg = replace_string(arg, "$BLUCYN$", BLUCYN);
                arg = replace_string(arg, "$BLUWHI$", BLUWHI);
                arg = replace_string(arg, "$MAGRED$", MAGRED);
                arg = replace_string(arg, "$MAGGRN$", MAGGRN);
                arg = replace_string(arg, "$MAGYEL$", MAGYEL);
                arg = replace_string(arg, "$MAGBLU$", MAGBLU);
                arg = replace_string(arg, "$MAGCYN$", MAGCYN);
                arg = replace_string(arg, "$MAGWHI$", MAGWHI);
                arg = replace_string(arg, "$CYNRED$", CYNRED);
                arg = replace_string(arg, "$CYNGRN$", CYNGRN);
                arg = replace_string(arg, "$CYNYEL$", CYNYEL);
                arg = replace_string(arg, "$CYNBLU$", CYNBLU);
                arg = replace_string(arg, "$CYNMAG$", CYNMAG);
                arg = replace_string(arg, "$CYNWHI$", CYNWHI);
                arg = replace_string(arg, "$WHIRED$", WHIRED);
                arg = replace_string(arg, "$WHIGRN$", WHIGRN);
                arg = replace_string(arg, "$WHIYEL$", WHIYEL);
                arg = replace_string(arg, "$WHIBLU$", WHIBLU);
                arg = replace_string(arg, "$WHIMAG$", WHIMAG);
                arg = replace_string(arg, "$WHICYN$", WHICYN);
        }

        arg += NOR;
        return arg;
/*
#endif
*/
}

// append color after the $N、$n、$w for the string color won't be
// break by the NOR after the name
string append_color(string arg, string default_color)
{
        arg = replace_string(arg, "$N", "$N" + default_color);
        arg = replace_string(arg, "$n", "$n" + default_color);
        arg = replace_string(arg, "$w", "$w" + default_color);
        arg = replace_string(arg, "$v", "$v" + default_color);
        return arg;
}

// change to english sigh to chinese
string chinese_desc(string arg)
{
        arg = replace_string(arg, ",", "，");
        arg = replace_string(arg, "!", "！");
        return arg;
}

// is the string1 be a substring of string2
int is_sub(string s_str, string m_str)
{
        if( !m_str || !s_str ) return 0;
        return strsrch("," + m_str + ",", "," + s_str + ",") != -1;
}

// add a s_str
string add_sub(string s_str, string m_str)
{
        string *slist;
        int i;

        if( !s_str || is_sub(s_str, m_str) )
                return m_str;

        slist = explode(s_str, ",");
        slist -= ({ "" });
        for (i = 0; i < sizeof(slist); i++)
                if( !is_sub(slist[i], m_str) )
                        if( m_str == 0 || m_str == "" )
                                m_str = slist[i];
                        else
                                m_str += "," + slist[i];

        return m_str;
}

// remove a s_str
string remove_sub(string s_str, string m_str)
{
        string *slist;
        string *trilist;

        if( !m_str || m_str == s_str ) return 0;
        slist = explode(m_str, ",") - ({ "" });
        trilist = explode(s_str, ",");
        slist -= trilist;
        if( !sizeof(slist) ) return 0;
        m_str = implode(slist, ",");
        return m_str;
}

// check the id is legal
int is_legal_id(string id)
{
        int i;

        if( !id ) return 0;

        for (i = 0; i < strlen(id); i++)
                if( id[i] < 'a' || id[i] > 'z' )
                        return 0;

        return 1;
}

// generate the short id for log
string log_id(object ob, int raw)
{
        string msg;
        if( raw ) return sprintf("%-8s", geteuid(ob));

        msg = sprintf("%s(%s)", ob->name(1), geteuid(ob));
        msg = sprintf("%-16s", msg);
        return msg;
}

// generate time
string log_time()
{
        string msg = ctime(time());

        msg = msg[4..6] + "/" + msg[8..9] + "/" +
              msg[20..23] + " " + msg[11..18];
        return msg;
}

// can the two man talk with together ?
int can_talk_with(object ob1, object ob2)
{
        if( !objectp(ob1) || !objectp(ob2) )
                return 0;

        if( !living(ob1) || !living(ob2) )
                return 0;

        if( environment(ob1) != environment(ob2) )
                return 0;

        if( ob1->is_fighting() || ob2->is_fighting() )
                return 0;

        return 1;
}

// build file crypt key
string file_crypt(string file)
{
#ifdef BINARY_SUPPORT
        return efun::file_crypt(file);
#else
        return "1234567890ABCDEF";
#endif
}

// check the file valid
int file_valid(string file)
{
#ifdef BINARY_SUPPORT
        return efun::file_valid(file);
#else
        return file_size(file) > 0;
#endif
}

// duplicate.c
mixed duplicate(mixed var)
{
        if( mapp(var) ) {
                mapping res;
                mixed *index;
                int i;

                res = var + ([]);
                i = sizeof(index = keys(var));
                while(i-- > 0)
                        if( pointerp(res[index[i]]) || mapp(res[index[i]]) )
                                res[index[i]] = duplicate(var[index[i]]);
                return res;
        }

        else if( pointerp(var) )
                return map_array(var, "duplicate", this_object());
        return var;
}

string color_capitalize(string arg)
{
        string str, ansi, word, *res = allocate(0);
        int i;

        if( !arg || !stringp(arg) ) return 0;
        foreach(str in explode(arg, " ")) {
                do
                {
                        i = sscanf(str, "%(\e\\[[0-9;#]*[HJMmrs])%s", ansi, word);
                        if( i == 2 )
                                str = sprintf("%s%s", ansi, efun::capitalize(word));
                        else
                                str = efun::capitalize(str);
                }
                while(i == 2 && word && word[0..1] == "\e[" && str = word);
                res += ({ str });
        }
        return implode(res, " ");
}

int sqrt3(int x)
{
        float y = 1.0 / 3.0;
        x = to_int(pow(to_float(x), y));
        return x;
}

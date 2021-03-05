/**********************************************************************************
*                                                                                 *
*       NameD.c 姓名生成程序                                                      *
*                                                                                 *
***********************************************************************************/

// By Zen(SnowMan.ZD) 19/09/2002
// Modified by Zen(SnowMan.ZD) 01/06/2003

// 头文件，拼音 <-> 汉字一一对应。

#include <names.h>

 int sur_size, f_size, m_size;
 string *key_sur = ({ });
 string *key_fname = ({ });
 string *key_mname = ({ });

 int query_sur_size(){ return sur_size; }
 int query_f_size(){ return f_size; }
 int query_m_size(){ return m_size; }

void create() 
{ 
        seteuid( getuid() ); 
        key_sur = keys(sur_name);
        key_fname = keys(f_name);
        key_mname = keys(m_name);
        sur_size = sizeof(sur_name);
        f_size = sizeof(f_name);
        m_size = sizeof(m_name);
}

 string *query_s_name(string str)
{       
        if( str )
                return sur_name[str];

        return key_sur; 
}
 string *query_m_name(string str)
{       
        if( str )
                return m_name[str];

        return key_mname; 
}
 string *query_f_name(string str)
{       
        if( str )
                return f_name[str];

        return key_fname; 
}

void remove()
{
}

 string *selete_namestring(string key, int sex)
{ 
        if( sex )
                return f_name[key]; 
        return m_name[key];
} 

/*
传回一个mapping：
        ([ name : "xxx", id : ({ "xxx", "xxx" }) ])
        name 为中文姓名，id 为拼音。
        如：
                ([ name : "高圆圆", id : ({ "gao yuanyuan", "gao", "yuanyuan" }) ])
        
可以指定的包括：
 gender = 性别, 1 = female, 0 = male.
 long_name = 名子的数目。long_name = -1， 只有一个名字，long_name = 0，随即1-2个名字，long_name > 0，两个名字。
 name_a = 姓
 name_b = 名
 name_c = 中间名, 如 一二三 的 二。

例子：
        random_name(0, 0, 0, 0, 0) -> 随机男性姓名，名为随机一个或两个字。
        random_name(1, 0, 0, 0, 0) -> 随机女性姓名，名为随机一个或两个字。
        random_name(0, 1, 0, 0, 0) -> 随机男性姓名，名两个字。
        random_name(0, -1, 0, 0, 0) -> 随机男性姓名，名一个字。
        random_name(1, 1, 0, 0, 0) -> 随机女性姓名，名两个字。
        random_name(0, -1, 0, 0, 0) -> 随机女性姓名，名一个字。
        
        random_name(0, 0, "李", 0, 0) -> 男姓，姓为李，名为随机一个或两个字。
        random_name(0, 0, 0, "强", 0) -> 男姓，姓随机，名为随机一个或两个字，但最后一个字为强。
        random_name(0, 1, "李", "强", 0) -> 男姓，姓李，名为两个字，最后一个字为强，中间随机。
        random_name(0, 1, "李", 0, "强") -> 男姓，姓李，名为两个字，中间一个字为强，最后随机。
        
        random_name(0, 0, 0, 0, "强") -> 男姓，姓随机，名随机，但如果是两个字，中间一个字为强。
*/
varargs  mapping random_name(int gender, int long_name, string name_a, string name_b, string name_c)
{       
        string str, str2, key, *names, vor, nach;
        int i;

        // write("name_a = " + name_a + ", name_b = " + name_b + ", name_c = " + name_c + "\n");
        
        // 给出了姓。
        if( name_a ){
                if( member_array(name_a, key_sur) != -1 ){
                        str = name_a;
                        vor = sur_name[str];
                }
        }
        else {
                i = random(sur_size);
                str = key_sur[i];
                vor = sur_name[str];
        }
        
        // 表格里没有这个字。
        if( !str || !vor )
                return 0;
        
        
        // 给出了中间名字(有long_name)，或名字(无long_name)。
        if( name_b ){
                if( gender ){
                        i = f_size;
                        while( i-- ){
                                if( member_array(name_b, f_name[key_fname[i]]) != -1 ){
                                        str2 = name_b;
                                        nach = key_fname[i];
                                        break;
                                }
                        }
                }
                else {
                        i = m_size;
                        while( i-- ){
                                if( member_array(name_b, m_name[key_mname[i]]) != -1 ){
                                        str2 = name_b;
                                        nach = key_mname[i];
                                        break;
                                }
                        }
                }
        }
        
        else {  
                if( gender ){
                        i = random(f_size);
                        key = key_fname[i];
                }
                else {
                        i = random(m_size);
                        key = key_mname[i];
                }
        
                names = selete_namestring(key, gender);
                str2 = names[random(sizeof(names))];
                nach = key;
        }
        
        // 表格里没有这个字。
        if( !str2 || !nach )
                return 0;
                
        // long_name = -1， 只有一个名字，long_name = 0，随即1-2个名字，long_name > 0，两个名字。
        if( ((!random(3) && !long_name) || long_name > 0) && long_name >= 0 ){
                if( name_c ){
                        if( gender ){
                                i = f_size;
                                while( i-- ){
                                        if( member_array(name_c, f_name[key_fname[i]]) != -1 ){
                                                str2 = name_c + str2;
                                                nach = key_fname[i] + nach;
                                                break;
                                        }
                                }
                        }
                        else {
                                i = m_size;
                                while( i-- ){
                                        if( member_array(name_c, m_name[key_mname[i]]) != -1 ){
                                                str2 = name_c + str2;
                                                nach = key_mname[i] + nach;
                                                break;
                                        }
                                }
                        }
                }
                else {
                        if( gender ){
                                i = random(f_size);
                                key = key_fname[i];
                        }
                        else {
                                i = random(m_size);
                                key = key_mname[i];
                        }
                        names = selete_namestring(key, gender);
                        str2 = names[random(sizeof(names))] + str2;
                        nach = key + nach;
                }
        }

        return ([ "name": str + str2,  "id": ({ vor + " " + nach, vor, nach }) ]); 
}

mapping man_name()
{
        return random_name(0);
}

mapping woman_name()
{
        return random_name(1);
}

// End Of File.

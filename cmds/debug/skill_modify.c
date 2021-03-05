// skill_modify.c by Silencer@fy4 workgroup

#define SKILL_FILE_NAME "daemon/skill_list.txt"
inherit F_CLEAN_UP;

int main(object me)
{
        int 	i, j, n, m, t,size, size_file, flag;
        string  file, first;
        string  arg_name, arg1, arg2, arg, line1, line2, tofile;
        string  *fileline, *extra;
	string  *format = ({ "file", "name", "type", "skill_class","effective_level","difficulty", 
        	"difficulty_r", "damage_level", "accuracy_level",
        	"practice_damage", "practice_force", "practice_limit", "bounce_ratio", "ic_effect",
        	"usage/animal-training",
		"usage/axe",
		"usage/blade",
		"usage/cursism",
		"usage/dagger",
		"usage/dodge",
		"usage/force",
		"usage/fork",
		"usage/hammer",
		"usage/herb",
		"usage/iron-cloth",
		"usage/literate",
		"usage/magic",
		"usage/move",
		"usage/parry",
		"usage/scratching",
		"usage/spear",
		"usage/spells",
		"usage/staff",
		"usage/stealing",
		"usage/sword",
		"usage/throwing",
		"usage/unarmed",
		"usage/whip",
		});
	
	mapping skill_data = ([]);        	
	string 	*line;
                      
        seteuid( geteuid(me) );
	
	line = explode(read_file(SKILL_FILE_NAME), "\n");
	write("读入数据文件/daemon/skill_list.txt，共计"+ (sizeof(line)-1) + "个技能。\n");

//	write(line[2]+"\n");

	size = sizeof(format);
	
	for ( t=1; t<sizeof(line); t++){
		
		reset_eval_cost();
		
		// 读入一行武功的全部参数
		first = line[t];
		for (i= 0;i<(size-1);i++)
		{
			sscanf(first,"%s\t%s",arg1,arg2);
			if (format[i] == "name" || format[i] == "type"
				|| format[i] == "skill_class")
				skill_data[format[i]] = "\""+ arg1 + "\"";
			else
				skill_data[format[i]] = arg1;
			first = arg2;		
			if (i==size-2)	
				skill_data[format[i+1]] = arg2;
		}
		
		// 读入此武功对应的技能文件
		file = "daemon/skill/"+ skill_data["file"] +".c";
		write(file + "\n");
		fileline = explode(read_file(file),"\n");
	
		tofile="daemon/skill/temp/"+ skill_data["file"] +".c";
	
		// 参看数据开始修正文件
		m = 0;
		extra= ({});
		
		for (i= 0; i<size; i++)
		{
			flag = 0;
			arg = skill_data[format[i]]; 
			if (arg=="0") continue;		// 空数据返回（注意不要让SKILL中非default为零）
						
			// 逐一搜索技能文件中的每一行
			size_file = sizeof (fileline);
			for (j=0;j<size_file;j++)
			{
				line2 = replace_string(fileline[j],"\t",""); 	//去TAB
				line2 = replace_string(line2, " ","");		//去空格
				if (sscanf(line2, "set(\"%s\"%s",arg1, arg2) == 2){
	    				if (format[i] == arg1){ 	//找到的话用新数据覆盖
	    					line2 = "\tset(\""+ format[i] + "\"," + arg+");";	    				
	    					fileline[j] = line2;
	    					flag = 1;
	    					break;
	    				}
	    			}  			
			}
			
			if (!flag) {	//没找到的话纪录下来
				switch( format[i])
				{		//取出一些不必写在单个技能文件里的,或者default的，
					case "file":	continue;
					case "practice_damage":	if (arg == "30")	continue;
					case "practice_force":  if (arg == "5")		continue;
					case "ic_effect":	if (skill_data["usage/iron-cloth"]=="0") continue;
					case "practice_limit":  if (arg == "1") continue;
				}	
					
				line2 = "\tset(\""+ format[i] + "\"," + arg+");";    			
				extra += ({ line2 });
	    			m++;
	    		}
	    	}		
				

		
		flag = 0;    
		for (i=0;i<size_file;i++)
		{
			line2 = replace_string(fileline[i],"\t",""); 	//去TAB
			line2 = replace_string(line2, " ","");		//去空格
			if (sscanf(line2, "set(\"%s\"%s",arg1, arg2) == 2){	// 去除过时的
				if (arg1 == "practice_bonus"
					||arg1 == "learn_bonus"
					|| arg1 == "black_white_ness"
				//	|| arg1 == "practice_limit"
					)
				continue;
			}			
			efun::write_file(tofile,fileline[i]+"\n",0);
			if (!flag && sizeof(extra)) {	//加入extra的数据在set("name"那一行后面。
				line1 = replace_string(fileline[i],"\t","");
				line1 = replace_string(line1, " ","");
				if (sscanf(line1,"set(\"name\"%s",arg_name) == 1)
				{	
					flag = 1;
					for (j=0;j<sizeof(extra);j++)
						efun::write_file(tofile,extra[j]+"\n",0);
				}	
			} 
		
		}
	}
	
	write ("全部文件处理完毕。\n");
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	skill_modify 
[0;1;37m────────────────────────────────[0m   

	此指令将/daemon/skill_list.txt文件中的数据读入后
	对照每一个具体文件进行修改，而后存储在/daemon/skill/temp/下
	也可在此命令中增加一些参量对数百个文件同时进行处理。
	
	此指令为巫师总调技能时使用，并未进行优化，（换言之，没有严格
	的检查，也没有BUG保护）	所以破坏性相当大。
	
	temp目录也许需要自己建立。
	
	如果需要使用，最基本的保护机制是运行完后，仔细检查temp目录下
	的文件是否符合需要，然后再将其覆盖到skill目录下。

相关指令：skill_collect        	
			
[0;1;37m────────────────────────────────[0m   
 
HELP
    );
    return 1;
}
 

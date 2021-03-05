// skill_collect.c by Silencer@fy4 workgroup

#define SKILL_FILE_NAME "daemon/skill_list.txt"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, m, size, n;
        string path, target, *files, skill;
        mapping skill_data;
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
                      	
        seteuid( geteuid(me) );
	write_file(SKILL_FILE_NAME, implode(format,"\t")+"\n",1);
	
	path = "/daemon/skill/";		
	files = get_dir(path);
    	    	  	
    	for(i=0; i<sizeof(files); i++) 
    	{
    	        reset_eval_cost();
    	        size = sizeof(files[i]);
        	if(files[i][(size-2)..size]==".c") {
  	        	n++;
  	        	skill_data =  SKILL_D(files[i])->query_skill_prop(); 	        	            
  	        	sscanf(files[i],"%s.c",skill);
  	        	for (m= 1; m < sizeof(format);m++)
  	        	{
  	        		skill += "\t"+ (string) skill_data[format[m]];
  	        	}
  	      	        write_file(SKILL_FILE_NAME, skill +"\n");
  	        }    
        }   	 
        
        write("数据文件写入/daemon/skill_list.txt，共计"+ n + "个技能。\n");
        return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	wskill 
[0;1;37m────────────────────────────────[0m   

	此指令将/daemon/skill/下的所有技能文件
	读入到/daemon/skill_list.txt文件中。
		
	文件格式为：
	
*format = "file", "name", "type",  "skill_class","effective_level","difficulty", 
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
        
        skill_list.txt的功能为：
        1。利用excel等软件进行各项排序检查，
        2。修改此文件并用skill_modify成批处理文件。
        	
相关指令：skill_modify
			
[0;1;37m────────────────────────────────[0m   
 
HELP
    );
    return 1;
}
 

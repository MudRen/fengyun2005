#include <dbase.h>
#include <login.h>
#include <ansi.h>

int prevent_learn(object me, string skill)
{
    	mapping my_family, family;
    	int	betrayer, mylvl, lvl;

    	lvl = this_object()->query_skill(skill, 1);
    	mylvl = me->query_skill(skill, 1);
    	if( betrayer = me->query("betrayer") )
    	{
        	if( mylvl >= lvl - betrayer * 20 )
        	{
            	message_vision("$N神色间似乎对$n不是十分信任，\n"
                           "也许是想起$p从前背叛师门的事情\n...。\n",
                	           this_object(), me );
            	command("say 嗯 .... \n师父能教你的都教了，其他的你自己练吧。");
            	return 1;
        	}
    	}

    	if( !me->is_apprentice_of(this_object()))
    	{
	        if( !mapp(my_family = me->query("family")) )  return 0;
	        if( !mapp(family = this_object()->query("family")) ) return 0;
	        if((my_family["family_name"] == family["family_name"]) )
	        {
	            command("hmm");
	            command("pat " + me->query("id"));
	            command("say 虽然你我同门，可是你并非我的弟子，"
	                    "你还是去找你师父学吧....");
	            return 1;
	        }
    	}

    	return 0;
}
	
string std_rank_title(object student)
{
    	int exp,i/*,gen*/;
    	string* ranks;
    	int * rank_levels;
    	string title;

    	ranks=query("ranks");
    	rank_levels=query("rank_levels");
    	if(!arrayp(rank_levels))
//        	rank_levels= ({76000,466000,1305000,2224000,3788000,
//                       4945000,10000000});
		rank_levels = ({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999});
					
    	if(!arrayp(ranks) || sizeof(rank_levels)+1 != sizeof(ranks))
    	{
        	if(!title = query("student_title"))
            		title = "弟子";
    	}        
    	else
    	{
        	exp = (int) student->query("combat_exp");
        	for(i=0;i<sizeof(rank_levels);i++)
            		if(exp < rank_levels[i]) break;
        	title=ranks[i];
    	}
    	// if(!stringp(ranks[i])) title=?
    	return title;
}

void re_rank(object student)
{
// 	int exp;
    
    	student->assign_title(std_rank_title(student),query("rank_nogen"));
}

int recruit_apprentice(object ob)
{
    	mapping my_family, family;
    	if( ob->is_apprentice_of( this_object() ) )	return 0;
    	if( !mapp(my_family = query("family")) ) return 0;
    	family = allocate_mapping(sizeof(my_family));
    	family["master_id"] = query("id");
    	family["master_name"] = query("name");
    	family["family_name"] = my_family["family_name"];
    	family["generation"] = my_family["generation"] + 1;
    	family["enter_time"] = time();
    	// privs = 0 for general 
    	family["privs"] = 0;
    	ob->set("family", family);
    	if (ob->query("class")!= query("class"))
    		ob->add("once_menpai/"+query("class"), 1);
    	ob->set("class", query("class"));
    	re_rank(ob);
    	return 1;
}


string 	query_chinese_class (string e_class) {
	
	if (!e_class)	return "无";
	switch (e_class) {
		case	"assassin":	return "金钱帮";
		case 	"bat":		return "蝙蝠岛";
		case	"ninja":	return "忍者";
		case	"legend":	return "铁雪";
		case	"huashan":	return "华山";
		case	"official":	return "官府";
		case	"beggar":	return "丐帮";
		case	"fugui":	return "富贵山庄";
		case	"shaolin":	return "少林";
		case	"lama":		return "大昭寺";
		case	"wudang":	return "武当";
		case	"taoist":	return "三清";
		case	"bonze":	return "兴国禅寺";
		case	"shenshui":	return "神水宫";
		case	"fighter":	return "万梅山庄";
		case	"demon":	return "魔教";
		case	"swordsman":	return "神剑山庄";
		case	"knight":	return "快活林";
		case	"yinshi":	return "帝王谷";
        case    "baiyun":   return "白云城";
		case	"huangshan":	return "黄山";
		case	"wolfmount":	return "狼山";
		case	"moon":	return "皓月天宫";
		default:		return "无";
	}
}

//	Master protecting player students.
//	You need add an action do_kill in init() for it to work.

int do_killing(string arg)
{
    	object player, victim;
    	string id,id_class,kill_msg;
    	
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    	if(living(victim))
    	{
	        if (ANNIE_D->check_buff(victim,"fugitive"))	return 0;
	        id_class=victim->query("class");
	        id=victim->query("id");
	       	if(id_class == query("class") && userp(victim) && player!=victim)
	        {
            		kill_msg = query("guard_msg")? query("guard_msg") : HIW"$N向$n喝道：伤我弟子，太过分了吧！\n"NOR;
            		message_vision(kill_msg, this_object(),player);
					this_object()->kill_ob(player);
            		player->kill_ob(this_object());
            		player->perform_busy(2);
            		return 0;
        	} 
    	}
    	return 0;
}	

int is_master(){
	return 1;
}
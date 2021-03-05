// Silencer@fengyun workgroup	June.2005, 
// No more skills between couples... xiaodie becomes a memeory.

#include <ansi.h>
inherit NPC;
inherit INQUIRY_MSG;

int check_other(object me);
int zero_skill(object me, string arg);

void create()
{
    	set_name("小蝶",({"xiaodie","xiao die"}));
//	set("title",HIR""NOR);
   	set("long","
小蝶这女孩子很特别。她长得很美，美极了，美丽的女孩子通常都知道自已有
多么美，而且随时不会忘记提醒别人这一点。小蝶却不同，她好像对自己是美
是丑都完全不在乎。她在人群中，也在笑，可是她笑得也和别人完全不同。无
论和多少人在一起，她都好像是一个人站在寒冷荒凉的旷野中。看着她，你忍
不住想拥抱她，怜爱她。\n");
     	
     	set("gender","女性");
     	     	
    	set("age",20); 	 	
    	set("int",52);
    	set("per",100);
    	set("cps",20);
    	set("str",10);
    	
    	set("combat_exp",10000);  
    	set("attitude", "friendly");
    	
    	set("skill_public",1);

/*	set("inquiry", ([
 		"学功夫":	CYN"嗯，你可以教我些功夫（teach xiaodie 技能名称），
你也可以让我放弃这些功夫（teach xiaodie abandon）。\n"NOR,
   	]));*/
   	
    	set("chat_chance",1);
    	set("chat_msg",({
		"小蝶眼睛里光采更明亮道：“你真的在流星掠过的时候，及时许了个愿？”\n",
		"小蝶轻轻道“一个人若连活都没有活过，怎么能死？”\n",
//		"小蝶说：女孩子学功夫不太好，不过，如果你一定想教我的话，我也可以学一些。\n",
    	}) );    	    	
    	
	setup();
    	carry_object(__DIR__"obj/redcloak")->wear();
    
}


void init() {
	add_action("do_hug",({"hug","kiss","kiss2",}));
//	add_action("do_teach","teach");
}


int recognize_apprentice(object ob)
{
    	if (!this_player()->query("m_success/星星楼")) {
    		message_vision("小蝶惊讶地说：“你是怎么进来的？快离开吧。”\n",this_player());
    		return 0;
    	}
    	if(this_object()->query("spouse")==this_player())
        	return 1;
	return 0;
}

/*
int do_teach(string arg){
	
	object me;
	object xiaodie;
	string err,who,skill_name;
	string *x_skill;
	int i;
	
	me=this_player();
	xiaodie=this_object();
	
	if (!this_player()->query("m_success/星星楼")) {
    		message_vision("小蝶惊讶地说：“你是怎么进来的？快离开吧。”\n",this_player());
    		return 1;
    	}
	if (sscanf(arg,"%s %s",who,skill_name)!=2)
		return notify_fail("格式：teach xiaodie 技能名称\n");
	
	if (who!="xiaodie")
		return notify_fail("格式：teach xiaodie 技能名称\n");
		
	if( !skill_name || skill_name=="" ) return notify_fail("你要教小蝶哪一项武功？\n");

	if (skill_name== "abandon") {
		if (xiaodie->query_skills())
			x_skill = keys(xiaodie->query_skills());
		
		if (sizeof(x_skill)>0) {
			for (i=0;i<sizeof(x_skill);i++) {
				xiaodie->delete_skill(x_skill[i]);
				me->delete("xiaodie/"+x_skill[i]);
				tell_object(me,"小蝶放弃了"+SKILL_D(x_skill[i])->name()+"。\n");
			}
		}
		message_vision("小蝶说：嗯，这些功夫本来就是学着玩的，不学就不学吧。\n",xiaodie);
		return 1;
	}
	
	
	if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) {
		return notify_fail("「" + skill_name + "」，有这种技能吗？\n");	
	}
	
        seteuid(getuid());
        err = catch( call_other(SKILL_D(skill_name)+".c", "???") );
        if (err)
                printf( "发生错误：\n%s\n", err );
	
	if( !me->query_skill(skill_name,1) && !zero_skill(me,skill_name))
		return notify_fail("你并没有学过这项武功。\n");
	
	if (sizeof(xiaodie->query_skills())>2)
		return notify_fail("小蝶最多只能学三门功夫。\n");
	
	if (check_other(me))
		return notify_fail("小蝶低着头说：这儿有外人，我不想舞刀弄枪的。\n");
		
	message_vision("$N和小蝶携着手，互相依偎着，说着悄悄话。\n",me);
	tell_object(me,"你把"+SKILL_D(skill_name)->name()+"的心诀传授给了小蝶。\n");
	xiaodie->set_skill(skill_name,me->query_skill(skill_name,1));
	me->set("xiaodie/"+skill_name,me->query_skill(skill_name,1));
	return 1;
	
}

*/

int do_hug (string arg){
	
	object xiaodie;
	
	if (arg != "小蝶" && arg != "xiao die" && arg != "xiaodie")  return 0;
	if (!xiaodie=present("xiao die",environment(this_object()))) return 0;
	if (check_other(this_player())) {
		tell_object(this_player(),"有旁人在场，过一会儿吧。\n");
		return 1;
	}
	call_out("event1",1,this_player(),0);
	return 1;
}



string *event1_msg=	({
	MAG"\n    你轻轻地拥抱着小蝶，望着她美丽动人的面貌，不禁怦然心动！\n"NOR,
	
	MAG"    小蝶依偎在你的怀里，眼中含情脉脉，脸上娇羞无限。\n"NOR,

 	MAG"    你轻轻地摸着小蝶那长长的秀发，将一口热气吹在她的脖子里。\n"NOR,

    	MAG"    小蝶只觉得浑身软绵绵的，显然是心摇神驰，芳心如醉。\n"NOR,
	
	MAG"    一个软软的声音从你的心底里冒出来：“但愿生生世世，永如今朝！”\n"NOR,

	MAG"    小蝶痴痴地看着你，痴痴地重复着“但愿生生世世，永如今朝！”\n"NOR,

    	MAG"    你轻轻卸去了小蝶的大红斗篷，拥着她洁白光滑的肌肤。\n"NOR,

	MAG"    小蝶在你的怀里微微地颤抖，好像是根被春风映动了的含羞草。\n"NOR,

	MAG"    你们沉浸在幸福的海洋里～～～～～～。\n"NOR,
    	
    	MAG"    。。。。。。。。。。。。。。。\n"NOR,
    	
    	MAG"    。。。。。。。。。。。。。\n"NOR,
    	
		MAG"    但愿生生世世，永如今朝！\n"NOR,
    	
    	MAG"    。。。。。。。。。\n"NOR,
    	
    	MAG"    。。。。。\n"NOR,
    	
    	MAG"    。。。\n"NOR,

});


void event1(object me, int count)
{
	mapping data;
	
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	if (check_other(me)) {
		tell_object(me,"有旁人在场，过一会儿吧。\n");
		return;
	}
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,MAG"    许久许久，你们相视一笑，站起身来。\n\n"NOR);
		
		if (REWARD_D->riddle_check(me,"菊园传奇")==14) {	 // incase some wiz summoned you in :D
			REWARD_D->riddle_done(me,"菊园传奇",100,1);
			data = ([
				"name":		"菊园传奇",
				"target":	me,
				"att_1":	"cps",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);	
		}		
		return;
	}
	else call_out("event1",2,me,count);
	return ;
}


int check_other(object me) {
	
	object *env;
	int i;
	
	env=all_inventory(environment(me));
	for (i=0;i<sizeof(env);i++) {
		if (env[i]!=me && userp(env[i])) return 1;
	}
	return 0;
}
	
/*	
	
int zero_skill(object me, string arg) {
	mapping learned_skill_points;
	
	learned_skill_points=me->query_learned();
	if (!learned_skill_points[arg]) return 0;
	return 1;
}	


*/
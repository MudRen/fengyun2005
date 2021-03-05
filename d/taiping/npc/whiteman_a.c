#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

int startit();

void create()
{

		set_name("白衣中年人",({"middle age man","man"}));
    	set("long", "一个高高瘦瘦的中年人，乃是武三爷手下的干将。\n");
		set("age",40);
		set("combat_exp", 5000000);
		
		set("sanye",1);
		
		set("max_kee", 8000);
		set("max_gin", 8000);
		set("max_sen", 8000);
		
		set("inquiry", ([
        	"号令":	 (: startit :),
        	"mission":	 (: startit :),
        	"三爷":	"三爷就是武三爷，明天这太平镇的一切就都是三爷的了。\n",
   		]));        	
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
	
		set("chat_chance",1);
    	set("chat_msg",({
				"白衣中年人说：只等三爷"YEL"号令"NOR"一到，咱们便攻入庄去！\n",
    	}) );   

		auto_npc_setup("xuebin",200,180,1,"/obj/weapon/","random","random",1);
		setup();
		carry_object(__DIR__"obj/whitecloth")->wear();
}


int	startit(){
	
	object me,young;
	
	me = this_player();
	
	
	if (REWARD_D->riddle_check(me,"喋血鹦鹉")!=11 && me->query("marks/quest/李家庄")!=1){
		command("say 什么人敢假传三爷号令，不想活了么！");
		return 1;
	}
	
	if (objectp(environment()->query("in_mission")) || is_fighting()) {
		command("say 先料理了手头的敌人再说吧！");
		return 1;
	}
		
	command("say 好，三爷号令已到，只许向前，不准后退，临阵脱逃者杀无赦！");
	if (young= present("young man"))
		young->ccommand("say 十年磨一剑，霜刃未曾试，今日把示君，有钱便有势。");
			
	message_vision(WHT"\n白衣中年人手指一弹，一道白色的焰火划破空中，李家庄内外顿时杀声震天。\n\n"NOR, me);
	
	message_vision(BLU"墙内脚步声错乱繁复，忽然跳出一个黑衣庄丁。\n"NOR, me);
	message_vision(BLU"黑衣庄丁叫道：太岁头上动土，老虎嘴上捋毛，不想活了？\n\n"NOR,me);
	
	environment()->set("in_mission", me);
	environment()->init_mission( 1, me->query("combat_exp"), me);
	return 1;
}
	
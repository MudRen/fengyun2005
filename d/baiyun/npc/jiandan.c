// XXDER@FY3
inherit SMART_NPC;
#include <ansi.h>
void create()
{
    set_name("剑胆" , ({ "jian dan","jian" }) );
    set("nickname",HIG"漱清泉"NOR);
    set("long", "一袭白衣迎风而振，散发击剑而歌，腰间随意挂着一个汉白玉的葫芦，徐徐的\n海风中荡漾着醉人的酒香。\n");
    set("age", 32);
    set("gender", "男性" );
    create_family("白云城",1, "狂生");
    set("per",40);
    set("combat_exp", 3000000);
    set("chat_chance", 1);
    set("chat_msg", ({
        "剑胆举起青葫芦饮了几口，铺开宣纸，笔走龙蛇，曼声长吟：往日书剑江湖，\n
长街奔马。今日明月醇酒，高山流水。快哉！\n",
        "剑胆击剑放歌：五花马，千金裘，呼儿将出换美酒，与尔同销万古愁！\n",
	}) );
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",180,150,0,"/obj/weapon/","fighter_w","siqi-sword",1);
	setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/jadegourd");
    carry_object("/d/baiyun/npc/obj/zhaodan")->wield();
}


int accept_object(object me, object obj)
{
	if (!obj->query("annie/by_hy_draw"))
		return 0;
	if (REWARD_D->riddle_check(me,"王图一梦") != 3)
		return 0;

	ccommand("emote 举起青葫芦饮了几口，打开画卷粗粗一瞥道：嘿，这妮子，我堂堂三尺男儿要这闺中之物何用。");
	ccommand("emote 随手将画卷收入怀中，也不睬你，径自舞剑放歌：五花马，千金裘，呼儿将出换美酒，与尔同销万古愁！");
	ccommand("emote 狂笑三声，复又大哭一痛，悲道：琴心啊琴心，你何时才能知晓我对你的千载深情啊。");
	ccommand("emote 枯立半晌，突然浑身抽搐，口吐白沫，不可思议的看着手中葫芦，嘶声道：大师兄，你。。这。。就是你送给剑胆的生辰大礼么？");
	ccommand("emote 扑通一声栽倒在龙台上。");

	set("long","如此潇洒的风流侠士，现在已神智不清，似乎中了巨毒，
要赶紧找其他三仙询问“"YEL"救治剑胆"NOR"”。\n");
	
	REWARD_D->riddle_set(me,"王图一梦",4);

	disable_player(HIR" <昏迷不醒>"NOR);
	set_temp("is_unconcious",1);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

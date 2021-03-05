#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("铁护卫", ({ "tie wei", "tie"}) );
        set("title",YEL"西方神教"NOR" 五护卫之 ");
        set("gender", "男性" );
        set("age", 32);
        set("long", "
西方神教复现江湖，天地人三长老，四金刚，金银铜铁锡五护卫。
这是西方神教五大护卫之一的铁护卫，负责外围巡查事务。\n");
        set("combat_exp", 4500000);
        set("attitude", "friendly");
        set("reward_npc",1);
        set("difficulty",2);
        set("group", "demon");
        set("vendetta_mark","demon");

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "铁护卫向你喝道：今天的口令？？\n",
                "铁护卫向你喝道：站住．亮你的腰牌？ 没腰牌就让你血溅当场！\n",
        }) );
	
	setup();
	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","illusionstick",4);
	carry_object(__DIR__"obj/blackrobe",([	
    						"name":  "铁卫服",
    						"long": "一件铁锈色的长袍，上面绣着一个“铁”字。\n",
    						 ]))->wear();
		set_skill("moon-blade",100);
}

void init(){
	::init();
	add_action("do_answer","answer");
}


int do_answer(string arg){
	object room;
	string *code = ({"挂印封侯","麒麟望月","宁死不屈","孤柏披忠","仙鹤展翅","汉柏凌寒","唐槐抱子","云列三台" });
	if (this_player()->query_temp("daimiao/passwd"))
		return notify_fail(this_object()->name()+"说：“教内的弟兄，开什么玩笑？”\n");
	if (this_player()->is_fighting())
		return notify_fail("先解决眼前的战斗再说吧！”\n");
	if (this_player()->query_temp("daimiao/spy"))
		return notify_fail(this_object()->name()+"说：“想乱猜？可惜你没有机会了！”\n");
	if (!arg)
		return notify_fail(this_object()->name()+"说：“再胡说八道小心我砍了你！”\n");
	if (member_array(arg,code)==-1)
		return notify_fail(this_object()->name()+"说：“再胡说八道小心我砍了你！”\n");
	if (arg != AREA_DAIMIAO"e_peidian"->pass_wd()) {
		message_vision("\n$N双目怒睁喝道：“哪里来的奸细，还不快快束手就擒！”\n",this_object());
		message_vision("几个神教弟子一拥而上把$N按倒在地捆了起来。\n",this_player());
		message("vision",this_player()->name()+"被拖走了。\n",environment(this_object()),this_player());
		tell_object(this_player(),"你昏昏沉沉地被押入了一间大殿。\n\n");
		room = find_object(AREA_DAIMIAO"w_peidian");
		if (!room) room = load_object(AREA_DAIMIAO"w_peidian");
		this_player()->move(AREA_DAIMIAO"w_peidian");
		this_player()->set_temp("daimiao/spy",1);
		this_player()->unconcious();
		return 1;
	}
	message_vision("$N退至一旁说：好，进去歇息吧，休要打扰教主。\n",this_object());
	this_player()->set_temp("daimiao/passwd",1);
	return 1;
}
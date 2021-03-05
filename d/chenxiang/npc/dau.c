#include <ansi.h>

inherit NPC;
int tell_him();
int well();

void create()
{
	set_name("贾员外的女儿", ({ "jianu" }) );
	set("gender", "女性" );
	set("age", 15);
	set("combat_exp", 3500);
	set("attitude", "friendly");
	set("per",30);
    set("chat_chance", 3);
    set("chat_msg", ({
                "贾员外的女儿问道：你是谁呀？\n",
                "贾员外的女儿道：你是不是我爹的好朋友？\n",
        }) );
        set("inquiry", ([
                "贾员外" : 	(: tell_him :),
                "爹" : 	(: tell_him :),
                "jia" : 	(: tell_him:),
                "井"	  : 	(: well :),
                "枯井"	  : 	(: well :),
                "well":  	(: well :),
                "拉一把": 	(: well :),
        ]));
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int tell_him()
{
 	object me;
 	me = this_player();
 	if(me->query_temp("marks/cured_jia")) 
	{
 		tell_object(me,"
贾女道：我爹他是个认为＂大恩不能报＂的人，你如果对他有过大恩的话那你就
死定了，他一定会想办法杀了你的。\n");
 	} else 
		tell_object(me,"贾女道：他是我爹呀，这还用问？\n");
	return 1;
}


int well ()	{
 	object me;
 	me = this_player();
 	
 	command("say 这个井深得很，贸贸然下去八成会摔死。\n");
 	
 	if(me->query_temp("marks/cured_jia")) 
	{
 		tell_object(me,CYN"贾女道：不过，看在你医好了我爹的分上，等会儿我就在上面拉你一把。\n"NOR);
 		me->set_temp("marks/asked_jianu",1);
 	} 
	return 1;

}
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老和尚", ({ "old monk","monk" }) );
	set("gender", "男性" );
	set("age", 57);
	set("long", "老和尚面色红润，目露精光，可惜的是在下巴上长了个大瘤子。\n");
	set("combat_exp", 100000);
	    set("inquiry", ([
        	"玉脖套" : 	"我这没有的卖，不过你可以买几块缅玉弧然后找石匠加工嘛。\n",
        	"yubotao" : "我这没有的卖，不过你可以买几块缅玉弧然后找石匠加工嘛。\n",
        	"王石匠" : 	"王石匠？他不会理你的，除非你认得他的大恩人。\n",
        	"wang" :	"王石匠？他不会理你的，除非你认得他的大恩人。\n",
        	"大恩人":	"谁治好了我的瘤子，谁就是我的大恩人。\n",
        	"恩人":		"谁治好了我的瘤子，谁就是我的大恩人。\n",
        ]));
	
	setup();
	carry_object(__DIR__"obj/mcloth")->wear();
}

int cure_arong(object me)
{
 	 if (query("cured")){
 		command("say 我没病啊，你不用费心了？");
 		return 1;
 	}
 	if (me->query_temp("marks/cured_monk")) {
 		command("say 自从你上次替我治过后，我已经好多了。");
 		return 1;
 	}
 	 	
 	if(!query("cured")) {
 		tell_object(me,"老和尚下巴上的大瘤子越来越小，慢慢消失了．．．\n");
 		set("long","老和尚面色红润，目露精光，满脸高兴的样子！\n");
 		tell_object(me,CYN"
老和尚高兴地拍拍你的头道：太好了，你知道么？贾员外的身上也有个大瘤子，
你如果可以帮他的话，他一定会给你很多好处！\n"NOR);
 		me->set_temp("marks/cured_monk",1);
 		set("cured",1);
 	} 
 	return 1;
}


void	reset(){
	
	set("cured",0);
	set("long","老和尚面色红润，目露精光，可惜的是在下巴上长了个大瘤子。\n");	
}

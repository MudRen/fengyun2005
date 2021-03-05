#include <ansi.h>
inherit NPC;

int fengxian();

void create()
{
        set_name("沈璧君", ({ "shen bijun","shen" }) );
        set("gender", "女性" );
        set("nickname", HIG"美人如玉"NOR );
        set("long","
她的美丽是任何人也无法形容的，有人用花来比拟美人，但花哪有她这样动人？
有人会说她像图画中人，但又有哪支画笔能画出她的风韵？就算是天上的仙子，也
绝没有这般温柔。无论任何人，只要瞧了她一眼，就永远也无法忘记。这就是武林
中的第一美人——沈壁君。  \n"
                );
        set("attitude", "peaceful");
        set("age", 24);
        set("per", 70);

        set("combat_exp", 600000);

        set("chat_chance", 1);
        set("chat_msg", ({
             "沈壁君星眸黯然，轻轻叹了口气，闭上眼睛。\n",
        }) );

        set_skill("unarmed", 50);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("move", 80);
        set_skill("fall-steps", 50);
        set_skill("meihua-shou", 50);
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "meihua-shou");

	set("inquiry", ([
      		"纱巾":  "哦，昔年我在风云城小住时，倒曾有很多雅客前来定做纱巾。
不过。。得看了纱巾才可确认。 \n",	
        	"缀满梅花的纱巾" : "哦，昔年我在风云城小住时，倒曾有很多雅客前来定做纱巾。
不过。。得看了纱巾才可确认。 \n",	
   		"孙小红":	"我离开风云城时，把布铺盘给了她，现在也不知道怎么样了。\n",
   		"吕凤先":	(: fengxian :),
   		"金钱帮":	"金钱帮是近年来江湖上的第一大帮，帮主上官金虹在风云城里建了总坛。\n",
   		"上官金虹":	"金钱帮是近年来江湖上的第一大帮，帮主上官金虹在风云城里建了总坛。\n",
   		"谈琴品画":	"action沈壁君微笑不语。\n",
   		"谈武论道":	"男人啊，就喜欢舞刀弄枪的。\n",
   		"宣武堂":	"action沈璧君摇摇头说：我只知道是在金钱帮中，具体可不清楚。\n",
   	]));                
   	
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}


int	accept_object( object who, object what) {
	if (what->query("name") == HIG"缀满梅花的纱巾"NOR) 
	{
		if (!what->query("real2") || !REWARD_D->check_m_success(who,"桃花林探幽")){
		message_vision(GRN"
沈璧君柳眉微皱，淡淡道：奇怪，这种质地的纱巾总觉得很眼熟，究竟是在哪
里见过呢？\n"NOR,who);
			return 0;
		}
		message_vision(WHT"
沈璧君诧异的哦了一声，回忆着道：这一款啊？那是江湖中名动一方的『银戟
温侯』吕凤先吕先生专程请我定制的，这红梅花。。。哦，真地很美呦。
 
沈璧君突然神情一黯，低声自语道：自那以后，小女子便再没能绣出什么了，
因为再也不会有那时的心境了。 \n"NOR,who);
		if (!REWARD_D->check_m_success(who, "初探金钱"))
			REWARD_D->riddle_set(who,"初探金钱",1);
		else
			message_vision(WHT"
沈璧君侧过脸去，眼中似有泪花闪动。。。。\n\n"NOR, who);

	//	who->set("maze/初闯武堂",1);
		return 1;
	}
	return 0;
}

int fengxian(){
	if (REWARD_D->check_m_success(this_player(),"桃花林探幽"))
		message_vision(GRN"
沈璧君道：吕先生实在是个雅客，那日与他谈琴品画，甚为投机，听说他应金
钱帮帮主上官金虹之邀，正在金钱帮宣武堂中谈武论道。 \n"NOR,this_player());
	else
		message_vision(GRN"
沈璧君道：吕先生实在是个雅客，那日与他谈琴品画，甚为投机。 \n"NOR,this_player());
	return 1;
}
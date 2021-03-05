#include <ansi.h>
inherit NPC;

int fill_water();
int quest();

void create()
{
	set_name("打水的妇人",({"woman"}));
	set("long", "一个衣衫不整的妇人，正在费劲地往羊皮酒袋里装水。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 500000);
	set("gender","女性");
	
	set("inquiry", ([
 		"gumu":	"这古董滩上出名的就是这些墓堆了，我当家的前些天掘到了一块很大的玉。\n",
 		"古董":	"这古董滩上出名的就是这些墓堆了，我当家的前些天掘到了一块很大的玉。\n",
 		"tomb":	"这古董滩上出名的就是这些墓堆了，我当家的前些天掘到了一块很大的玉。\n",
 		"古董滩": "这古董滩上出名的就是这些墓堆了，我当家的前些天掘到了一块很大的玉。\n",
 		"古墓":	"这古董滩上出名的就是这些墓堆了，我当家的前些天掘到了一块很大的玉。\n",
 		"金银财宝": "这古董滩上出名的就是这些墓堆了，我当家的前些天掘到了一块很大的玉。\n",	
 		"玉": "这玉么，三十两黄金我就卖给你。\n",
 		"yu": "这玉么，三十两黄金我就卖给你。\n",
 		"jade": "这玉么，三十两黄金我就卖给你。\n",
 		"古董三":	(: quest() :),
   	]));
   		
	set("chat_chance", 2);
        set("chat_msg", ({
                "妇人说：你也多带点水吧，出了关就靠它了。\n",
                "妇人神秘兮兮地说:“听说这古墓里都是"YEL"金银财宝"GRN"。”\n",
                (: fill_water() :),
        }) );
	set("sold",0);	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/d/guanwai/npc/obj/wineskin");
	carry_object(__DIR__"obj/bucket");
	
}

int fill_water() {
	command("fill bucket");
	return 1;
}

int accept_object(object who, object ob)
{
	object jade;
	if (ob->query("thief_obj")){
		command("ack");
		command("say 这不清不白的东西，咱不能要。");
		return 0;
	}
		
	
	if( ob->value() >= 300000) {
 	  	if (query("sold") || REWARD_D->riddle_check(who,"紫晶之谜")!=3) {
          	if (objectp(query("buyer"))) 
           		command("say 你来晚了，我的玉刚给"+query("buyer")->name()+"买走。");
           	else
           		command("say 你来晚了，我的玉刚给人买走。");
           	return 0;
        }
        command( "say 好吧，这块玉我就卖给你。");
        jade = new(__DIR__"obj/jade");
        if (!jade->move(who))
        	jade->move(this_object());
        else
        	message_vision("打水的妇人神秘兮兮地塞给$N一样东西。\n",who);
        set("sold",1);
        set("buyer",who);
        return 1;
    } else {
        command("say 这么点钱怎么够呢？\n");
        return 0;
    }
    return 0;
} 


int	quest(){
	object me = this_player();
	
	if (REWARD_D->riddle_check(me,"紫晶之谜")!=2)	return 0;

	message_vision(CYN"$N狐疑地看了$n几眼说：你竟然知道我当家的名字，你想找他？\n",this_object(),me);
	tell_object(me,CYN"妇人凑在你耳边悄悄地说：一个月前，他到西边去了，据说有伙强盗有大买卖！\n"NOR);
	tell_object(me,CYN"妇人说：临行前他留下一块玉，你想要我可以卖给你！\n"NOR);
	REWARD_D->riddle_set(me,"紫晶之谜",3);
	return 1;
}
		
	
		
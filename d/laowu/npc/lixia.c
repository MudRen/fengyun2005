// keeper.c
#include <ansi.h>
inherit NPC;

int hubby();

void create()
{
        set_name("李霞", ({ "lixia" }) );
        set("gender", "女性" );
        set("age", 24);
		set("per",5);
        set("long","这个女人看起来二十多岁了，看著她粗壮的身形，你觉得．．．。\n");
        set("combat_exp", 4000);
        set("chat_chance", 1);
        set("chat_msg", ({
				"李霞暗暗嘀咕：没想到这牌子这么烫手，还是快快出手为上。\n",
        }) );
        
        set("inquiry",	([
            	"罗刹牌":"action李霞犹犹豫豫地看着你说：这牌子可不能白给。\n",
            	"蓝胡子": (: hubby() :),
            	"炸药": 	"你去找点来我看看。",	
            	"白给":		(: command("heihei") :),
        
        ]));
        
        set("attitude", "friendly");
        setup();
}

int accept_object(object who, object ob)
{
        int val;
        string msg;

		if (REWARD_D->riddle_check(who,"计取罗刹")==3) {
			if ( !ob->query("explosive")) {
				command("say 这个，恐怕什么用也没有。");
				return 0;
			}
			if (ob->query("explosive") == 1 ){
				if (ob->query("name")=="雷火珠")
					tell_object(who, CYN"
李霞看了看雷火珠说：江南霹雳堂的火药天下闻名，只是，你看看，这个雷火珠
已经受潮了。不过，既然帝王谷有一个就会有第二个，你在那附近多找找，我知
道当年雷动天曾经在那儿的山穴中囤积过一批火药。\n"NOR);
				else
					tell_object(who,CYN"李霞急躁地说：不行不行，这个威力太差。\n"NOR);
				return 0;
			}
			command("say 好，你到冰河，去把罗刹牌炸（Bomb）出来，我们就两清了。");
			return 0;
		}		
		
        if (!who->query_temp("marks/lixia_m"))
        {
        	message_vision(CYN"李霞说：钱现在我还不要，千万记得别把我藏身之地说出去。\n"NOR,who);
        	return 0;
        }	
        
        val = ob->value();
        
        if( val >= 100000 ) 
		{
        	msg = "我把它埋在冰河下面了，要拿就需要把它炸出来。不过今年大寒，
冰冻三尺，寻常的炸药恐怕不行，你去找点来我看看。\n";
			message_vision(CYN+msg+NOR, who);
			REWARD_D->riddle_set(who,"计取罗刹",3);
        	return 1;
		}
		msg = "这么点，我还指靠它过下半辈子呢。\n";
		message_vision(CYN+msg+NOR, who);
		return 0;
}


int hubby(){
	
		object who = this_player();
		
		if (REWARD_D->riddle_check(who,"计取罗刹")!=2)
        {
        	command("say 蓝胡子？就是那个专门娶老婆杀老婆的？");
        	command("shiver");
        	return 1;
        }
        
        message_vision(CYN"
李霞叹了口气说：既然蓝胡子已经找上门来了，我还是保命要紧。这样吧，十两金子，
我可以搭船逃离此地，这牌子就任由你做主了！\n"NOR, who);
        who->set_temp("marks/lixia_m",1);
        return 1;
}
        
        
        
        	
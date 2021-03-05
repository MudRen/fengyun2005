inherit NPC;
#define MONEY_VALUE 100000
#include <ansi.h>

void create()
{
        set_name("韩掌柜", ({ "han zhanggui","zhanggui","han" }) );
    	set("nickname","一阵风");
        set("gender", "男性" );
        set("age", 54);
               
        set("long","一个胖子，很难想象他当年能行走江湖，更不要说做什么有来头的江湖人了。\n");

        set("combat_exp", 10000);
        set("inquiry", ([
                "抢劫" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
                "rob" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
                "阴阳和合散": "action韩掌柜莫测高深地笑了起来说：风高月黑夜，摘花盗香时，晚上。。。。\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object  ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);
}

int greeting(object ob)
{	
	if (!ob || environment(ob) != environment())	return 1;
		
	if (random(100)>70 )
	{
        if(NATURE_D->get_current_day_phase() == 0) 
		{
			message_vision("$N脸上浮起了一种诡异的笑容。\n",this_object(),ob);
			command("whisper "+ob->query("id")+" 当年我一阵风韩风也是黑道上的角儿，
如今年纪大了，就洗手不干了，不过．．．\n");
			command("grin");
			return 1; 
		}
		else 
		{
			command("heihei");
			command("say 小人这有好些好东西，不过么，白天实在不方便，这些
天镇上官差也多，大爷不妨晚上来瞧瞧。");
			return 1;
		}
	}
	else
		return 0;
}

int accept_object(object me, object obj)
{	
	object hhs, ob1;
	
    if(NATURE_D->get_current_day_phase() < 2) 
	{ 
       	if (query("gived")) {
       		if (objectp(ob1 = query("gived_who")))
       			command("whisper "+ me->get_id() + " 晚了，已经给"+ ob1->name(1) + "拿走了。\n");
       		else
       			command("say 晚了，已经被人拿走了。。\n");
       		return 0;
       	} 
       	
       	if( (int) obj->value() >= (MONEY_VALUE+ random(MONEY_VALUE)) && !query("gived"))
       	{
        	command("grin");
        	command("say 吃了小人这阴阳和合散，报她贞女烈妇也变成淫娃荡妇！\n");
       		hhs = new(__DIR__"obj/hehesan");
       		if(hhs)	hhs->move(me);
       		set("gived",1);
       		set("gived_who", me);
       		message_vision("$N拿出"+HIY "阴阳和合散"NOR+"给$n。\n",this_object(),me);
       		return 1;       
       	}

        if( !obj->value() &&  !obj->query("value")) return 0;
        command("heihei");
        command("say 这点儿，恐怕还换不了咱成名的暗器。。厄。。暗药！");
        return 0;
	}
	else
	{
		command("heihei");
        tell_object(me,"韩掌柜在你耳边悄悄说：白天人多眼杂，等天黑了再来吧。\n");
        return 0;
    }
	return 0;
}


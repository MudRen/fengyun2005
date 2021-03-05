inherit NPC;
void create()
{
    	set_name("小云雀", ({ "skylark" }) );
        set("race", "飞禽");
        set("age", 2);
        set("gender", "雌性");
        set("long", "羽毛梳理得洁净整齐，叽叽喳喳很可爱的小云雀，抓住（catch）它吧。。。 \n");
	set("combat_exp", 10000);
        set("attitude","peaceful");
        
        set_temp("apply/dodge", 100);
	set("chat_chance", 1);
        set("chat_msg", ({
        	"小云雀叽叽喳喳欢快的叫着！ \n",
        	"小云雀用嘴整理羽毛。 \n"
        }) );
        setup();
}

void init()
{	
        add_action("do_catch", "catch");
}

int do_catch(string arg)
{
	object *inv;
	object me;
	object bird;
	object birdcase;
	int i;
	me = this_player();
	bird = this_object();
	inv = all_inventory(me);
	
	if( !arg || arg != "skylark" )
                return notify_fail("你要抓什么？\n");
	
	if( random(40) > me->query("kar") )
	{
		message_vision("$N扑楞扑楞翅膀飞入云巅，一下子消失得无影无综。\n" , bird);
		destruct(bird);
	}
	else
	{
		for(i=0; i<sizeof(inv); i++)
        	if(inv[i]->query("contains"))
        	{
			birdcase = inv[i];
		}
        }
       
        if ( birdcase && random(3) )
        {
        	birdcase->set("contains",0);
        	birdcase->set("skylark",1);
        	message_vision("$N一把抓住$n，然后小心翼翼地把$n放入鸟笼里。\n" , me,bird);
        	birdcase->set("long", "一个精致的小鸟笼，呈方形，一端有向上抽的门。\n里边有只活泼的小云雀。\n");
        	destruct(bird);
        	me->start_busy(3);
        }
        else
        {
        	message_vision("$N刚想把$n抓牢，没有料到一个踉跄，$n扑哧一下从$N手中飞走了．\n" , me,bird);
        	destruct(bird);
 	}
	return 1;
}
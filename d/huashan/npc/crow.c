#include <ansi.h>
inherit NPC;
mapping *way;
mapping *read_table(string file);
void create()
{
    set_name("红嘴乌鸦", ({ "crow" }) );
    set("race", "飞禽");
    set("age", 1);
    set("gender", "雄性");
    set("long", "这是只整天叽叽咕咕的红嘴乌鸦。\n");
    set("attitude","peaceful");
    
	set("weight", 200);
   
    	set("combat_exp", 800000);
		
	set_temp("apply/attack", 200);
	set_temp("apply/dodge",200);
	set_temp("apply/move",320);
	set_temp("apply/damage",50);
	set_temp("apply/armor", 50);
    
    set("chat_chance", 1);
    set("chat_msg", ({
    	"红嘴乌鸦对公冶长 哇~~啊~ 哇~~啊~ 叫着 \n",
	}) );
    setup();
}
void init()
{
	::init();
	add_action("do_follow","follow");
}

void followme(object player)
{
	object room;
	room = find_object("/d/huashan/qipan");
	if (room != environment())
	{
		return;
	}
	if (player && environment(player) == environment())
	{
		message_vision("$N听了公冶长的话，兴奋地飞了起来，绕着$n忽前忽后 
似乎要$n跟它去什么地方。\n",this_object(),player );
		player->set_temp("marks/ablefollowcrow",1);
		//add_action("do_follow","follow");
	}
}

void get_quest(string file)
{   
    way=read_table(file);
}
mapping *read_table(string file)
{
    string *line, *field, *format;
    mapping *data;
    int i, rn, fn;

    line = explode(read_file(file), "\n");
    data = ({});
    for(i=0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !pointerp(field) ) {
            field = explode( line[i], ":" );
            continue;
        }
        if( !pointerp(format) ) {
            format = explode( line[i], ":" );
            continue;
        }
        break;
    }

    for( rn = 0, fn = 0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
        sscanf( line[i], format[fn], data[rn][field[fn]] );
        fn = (++fn) % sizeof(field);
        if( !fn ) ++rn;
    }
    return data;
}
int arrive(object me)
{
	set("chat_chance", 1);
	set("chat_msg", ({"红嘴乌鸦对公冶长 哇~~啊~ 哇~~啊~ 叫着 \n",}) );
	set("marks/in_follow",0);
	message_vision("到了这里，$N更加兴奋，哇的一声飞过灌木。 \n",this_object());
	if (objectp(me) && me->query_leader() == this_object())
	{
		me->set_leader(0);	
		me->set_temp("followcrow",1);
		message_vision("$N试着跟上红嘴乌鸦，可是密密的灌木林挡住了$N的去路。\n",me);
		message_vision("$N再抬头看时，红嘴乌鸦已不见踪影。\n",me);
	}
	//should i destruct this object or move it back?
	destruct(this_object());
	return 1;
}
void go(object me)
{
	string		*dirc = ({ "东", "南", "西", "北" });
	int i,j,k;
	object room;
    string *cmds;
    remove_call_out("go");
    for(i=0;i<sizeof(way);i++)
    {
        if (base_name(environment()) != way[i]["room_file"]) continue;
        cmds=explode(way[i]["cmd_table"],";");
        break;
    }
    
    if (i>=sizeof(way))
    {   
        random_move();
        call_out("go",2,me);
        return;
    }
    for(j=0;j<sizeof(cmds);j++)
        command(cmds[j]);
    if (way[i]["delay_time"]<0)
    {
		//use move from here seems lame
		room = environment();
		k = random(3);
		message( "vision", this_object()->name() +  "往" + dirc[k] + "离开 。\n", environment(this_object()), ({this_object()}) );
		this_object()->move("/d/huashan/duanshan");
		message( "vision", this_object()->name() + 
				(this_object()->is_naked() ? "赤身裸体" : "") 
				+  "走了过来。\n", environment(this_object()), ({this_object()}) );
		if (me && present(me,room))
		{
			message( "vision", me->name() + "往" + dirc[k] + "离开 。\n", environment(me), ({me}) );
			me->move("/d/huashan/duanshan");
			message( "vision", me->name() + 
				(me->is_naked() ? "赤身裸体" : "") 
				+ "走了过来。\n", environment(me), ({me}) );
		}
		arrive(me);
        return;
	}
    call_out("go",way[i]["delay_time"],me);
    return;
}
int do_follow(string arg)
{
	object player;
	player = this_player();
	if (arg !="crow" && arg!="红嘴乌鸦")
	{
		return 0;
	}
	if (!player->query_temp("marks/ablefollowcrow"))
	{
		tell_object(player,"红嘴乌鸦不爱答理你。。。\n");
		return 1;
	}
	if (query("marks/in_follow"))
	{
		tell_object(player,"红嘴乌鸦现在正在给别人带路呢。。。 \n");
		return 1;
	}
	set("chat_chance", 10);
	set("chat_msg", ({"红嘴乌鸦兴奋的扑腾着翅膀，飞在前面。 \n",}) );
	player->set_leader(this_object());
	set("marks/in_follow",1);
	player->delete_temp("marks/ablefollowcrow");
	get_quest(__DIR__"crowway");
    call_out("go",2,player);
}
int return_home(object home)
{
        //if crow is in action, don't make it return home
        if (query("marks/in_follow"))
        {
                return 1;
        }
        ::return_home(home);

}

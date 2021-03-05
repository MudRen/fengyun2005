#include <room.h>  
inherit ROOM;
void create()
{
  set("short","方舟外");
  set("long",@LONG
骤眼望去，但见池中碧波粼粼，四面青山绿树，好一片山光水色，但定睛一望，
才发现这一片池水宽广不过十余丈，四面的青山绿水不过是画在壁上的丹青图画，
只是画得委实太过逼真，远近分明，景致宛如，颜色更是鲜艳欲滴，使山色看来更
如覆苍翠，就白云飘渺间那几只引吭长唳的天鹅，也画得似要破壁飞出。再瞧池面
粼粼绿波之上，也有几只白鹅浮沉其间，还有一艘小巧玲珑的方舟飘浮水上，只是
方舟四面黑纱低垂几达水面，谁也瞧不清舟中情况，只瞧见一缕轻烟带着一阵清香
之气飘渺自垂帘中四散而出。
LONG
  );
  	set("exits/south" ,__DIR__"blkroom");
    set("objects",([
    	__DIR__"npc/zhuo" : 1,
    	__DIR__"npc/feng" : 1,
    ]) );

	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
 }
 
 
void reset()
{   
	object *inv;
	int i,no_reset;
	inv=all_inventory(this_object());
	for (i=0;i<sizeof(inv);i++)
	{
	    if(base_name(inv[i])==__DIR__"npc/lishi")
		{
			if (!inv[i]->is_fighting())                  
		    	destruct(inv[i]);
		    else
		    	no_reset=1;
		}
		else
		if(base_name(inv[i])==__DIR__"npc/feng2" )
		{
			if (!inv[i]->is_fighting())
				destruct(inv[i]);
			else  
				no_reset=1;
		}
	}
	if(!no_reset) ::reset();
}

void init()
{
	add_action("do_swim","swim");
}

int arrive(object me, object room)
{
        if(me && environment(me) == this_object())
        {
        me->move(room);
        message_vision("$N从池水中爬了上来。\n",me);
        }
        return 1;
}

int do_swim(string arg)
{
	object me;
	object room;
	me=this_player();
	if(arg == "池水" || arg == "pond" || !arg) {
		if(me->is_fighting()) return 0;
		if(random(2)) return notify_fail("池水太深，游不过去！\n");
		message_vision("$N扑通一声跳入池水，一阵狗刨，向方舟游去！\n",me);
		me->start_busy(7);
		if(!objectp(room=find_object(__DIR__"ark")))
			room=load_object(__DIR__"ark");
		call_out("arrive",7,me,room);
		return 1;
	}
	return 0;
}

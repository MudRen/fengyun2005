inherit ROOM;
string bank();
void create()
{
        set("short", "城北小路");
        set("long", @LONG
弯弯曲曲的小路向东西方向延伸。路的旁边是风云城的护城河，河的另外一边
就是高大的风云城城墙了。从这里可以看到城墙上值勤的士兵在站岗。河堤上长满
了绿草。微风拂来，一股的泥土的气息。东边就是风云城的干线南北大道。北面是
一大片茂密的竹林小径，好象听的见有人说话的声音，又好象是风吹竹叶的声音。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north":__DIR__"bomboo",
  "east" : __DIR__"fynorth",
  "southwest" : __DIR__"road2",
]));
	set("item_desc", ([
		"河堤" : (: bank :),
		"bank" : (: bank :),
		"绿草" : (: bank :),
		"grass" : (: bank :),
		]));
        set("outdoors", "fengyun");
	set("coor/x",-60);
	set("coor/y",320);
	set("coor/z",0);

        setup();
}

string bank(){
	object me;
	me = this_player();
	tell_object(me, "你注意到河堤上有一处绿草颜色比周围要浅，似乎经常有人踩过。\n");
	tell_object(me, "你也许可以去踩踩看。（stamp）\n");
	add_action("do_stamp", "stamp");
	return "";
}

int do_stamp(string arg){
	object me, room;
	me = this_player();
	if(!arg || (arg != "grass" && arg != "绿草")){
		return notify_fail("你要踩什么？\n");
	}
        message_vision("$N小心翼翼地走到草地上，四处踩了踩。\n", me);
		if (!REWARD_D->check_m_success( me,"勇探地牢"))
			return notify_fail("你觉得脚下的土地软软地踩上去很舒服。\n");
		
		message_vision("只听咯吱吱一阵铁索绞动的声音，$N脚下的草地突然露出了一个向上的洞口。\n", me);
		message_vision("$N的身子一下子陷入了洞中，草地在$N身后又无声无息地合上了。\n\n",me);
		room = find_object("/d/cave/yd");
		if(!objectp(room)){
            room = load_object("/d/cave/yd");
		}
		me->move("/d/cave/yd");
		return 1;	
}

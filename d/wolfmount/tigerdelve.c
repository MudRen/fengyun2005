inherit ROOM;

void create()
{
	set("short", "虎穴");

	set("long", @LONG
一个很宽阔的石洞，洞中很暗，黑漆漆一片，几乎什么都看不见，但不时空气
闪着绿色的磷光，借着这微弱诡异的光线，你朝四下望去，满地都是腐烂的肉，腐
烂的尸骸，骇人的枯骨。
LONG);

	set("type","street");
	set("exits",([
		"out":__DIR__"18pan1",
	]) );
	set("indoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/wuyi":1,
     		__DIR__"npc/longzi":1,
		__DIR__"obj/tigerbone":2,
    	]) ); 
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",-30);
	setup();
}

void reset(){
        object item;
        int i;
        ::reset();
      
	if(!present("tiger bone", this_object())){
                for (i=1; i<=2 ; i++) {
                	item = new(__DIR__"obj/tigerbone");
	                if(objectp(item)){
                        item->move(this_object());
                	}
	        }
        }
        return;
}       
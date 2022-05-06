$TTL 60000
@   IN SOA abc.com. root.abc.com. ( 
    1 ; serial
    28800 ; refresh
    14400 ; retry
    3600000 ; expire
    86400 ; ttl
    )
@       IN  NS      dns.abc.com.
dns     IN  A       192.168.1.10
www     IN  A       192.168.1.100
web     IN  CNAME   www.abc.com.
pc      IN  A       192.168.2.100
router1 IN  A       192.168.1.1
router2 IN  A       192.168.2.1

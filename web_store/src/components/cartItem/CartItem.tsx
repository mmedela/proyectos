import { Button, Stack } from "react-bootstrap";
import { useShoppingCart } from "../../context/shopingCartContext/ShopingCartContext";
import storeItems from "../../data/items.json";
import { formatPrice } from "../../utils/FormatPrice";

type cartItem = {
    id: number
    quantity: number
};

export function CartItem({id, quantity}: cartItem){
    const {removeFromCart} = useShoppingCart();
    const item = storeItems.find(i => i.id === id);
    if(item == null) return null;

    return (
        <Stack direction="horizontal" gap={2} className="d-flex align-items-center">
            <img src={item.imgUrl} style={{width: "125px", height: "75px", objectFit: "cover"}} alt="" />
            <div className="me-auto">
                <div> 
                    {item.name}
                    {
                        quantity > 1 &&( 
                        <span 
                            className="text-muted"
                            style={{fontSize: ".65rem"}}
                        >
                            x{quantity}
                        </span>
                    )}
                </div>
                <div className="text-muted" style={{fontSize: ".75rem"}}>{formatPrice(item.price)}</div>
            </div>
            <div>{formatPrice(item.price * quantity)}</div>
            <Button variant="outline-danger" size="sm" onClick={()=> removeFromCart(item.id)}>&times;</Button>
        </Stack>
    );
}
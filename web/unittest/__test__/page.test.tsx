import '@testing-library/jest-dom'
import { render, screen } from '@testing-library/react'
import Page from '../app/page'
 
describe('Page', () => {
  it('renders', () => {
    render(<Page />)
 
    const paragraph = screen.getByText('Web programming sucks')
 
    expect(paragraph).toBeInTheDocument()
  })
})